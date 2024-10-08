// Parser.cpp
#include "Parser.h"
#include "ExpressionWorld.h"
#include "Statement.h"

Parser::Parser(std::vector<Token> tokens) : tokens(tokens) {}

Parser::~Parser() {}

Statement* Parser::declaration() {

  try {
    if (match({TokenType::VAR})) {
      return varDeclaration();
    }
    else if (match({TokenType::DEF})) {
      return function("function");
    }
    return statement();
  } catch (const ParseError& e) {
    CRIT << "Parse error: " << e.what() << ENDL;
    synchronize();
    return nullptr;
  }
}

Expression* Parser::expression() {
  return assignment();
}

Expression* Parser::assignment() {
  // Get the result of an equality expression
  Expression* expr = equality();

  if (match({TokenType::EQUAL})) {
    // Get the previous token and recursively call assignment
    Token equals = previous();
    Expression* value = assignment();

    // Use dynamic_cast to check if expr is of type Variable
    if (auto varExpr = dynamic_cast<Variable*>(expr)) {
      Token name = varExpr->name;
      return new Assign(name, value);
    }

    error(equals, "Invalid assignment target.");
  }

  return expr;
}

Expression* Parser::equality() {
  Expression* expr = comparison();

  while (match({TokenType::BANG_EQUAL, TokenType::EQUAL_EQUAL})) {
    Token op = previous();
    Expression* right = comparison();
    expr = new Binary(expr, op, right);
  }

  return expr;
}

Expression* Parser::comparison() {
  Expression* expr = term();

  while (match({TokenType::GREATER, TokenType::GREATER_EQUAL, TokenType::LESS,
                TokenType::LESS_EQUAL})) {
    Token op = previous();
    Expression* right = term();
    expr = new Binary(expr, op, right);
  }

  return expr;
}

Expression* Parser::term() {
  Expression* expr = factor();

  while (match({TokenType::MINUS, TokenType::PLUS})) {
    Token op = previous();
    Expression* right = factor();
    expr = new Binary(expr, op, right);
  }

  return expr;
}

Expression* Parser::factor() {
  Expression* expr = unary();

  while (match({TokenType::SLASH, TokenType::STAR})) {
    Token op = previous();
    Expression* right = unary();
    expr = new Binary(expr, op, right);
  }

  return expr;
}

Expression* Parser::unary() {
  if (match({TokenType::BANG, TokenType::MINUS})) {
    Token op = previous();
    Expression* right = unary();
    return new Unary(op, right);
  }
  return call();
}

Expression* Parser::primary() {
  if (match({TokenType::FALSE}))
    return new LiteralBool(false);
  else if (match({TokenType::TRUE}))
    return new LiteralBool(true);
  else if (match({TokenType::NIL}))
    return new LiteralInt(0);  // @TODO - how to handle NULL values?
  else if (match({TokenType::NUMBER})) {
    // check if the given value is an integer or a double
    if (previous().literal.find('.') != std::string::npos) {  // is a double
      return new LiteralDouble(std::stod(previous().literal));
    } else {  // is an integer
      return new LiteralInt(std::stoi(previous().literal));
    }
  } else if (match({TokenType::STRING})) {
    return new LiteralString(previous().literal);
  } else if (match({TokenType::LEFT_PAREN})) {
    Expression* expr = expression();
    consume(TokenType::RIGHT_PAREN, "Expect ')' after expression.");
    return new Grouping(expr);
  } else if (match({TokenType::IDENTIFIER})) {
    return new Variable(previous());
  }

  throw ParseError("Expect expression.");
}

Expression* Parser::call() {
  Expression* expr = primary();
  
  while(true) {
    if (match({TokenType::LEFT_PAREN})) {
      expr = finishCall(expr);
    } else {
      break;
    }
  }

  return expr;
}

Expression* Parser::logicalOr() {
  Expression* expr = logicalAnd();

  while (match({TokenType::OR})) {
    Token op = previous();
    Expression* right = logicalAnd();
    expr = new Logical(expr, op, right);
  }

  return expr;
}

Expression* Parser::logicalAnd() {
  Expression* expr = equality();

  while (match({TokenType::AND})) {
    Token op = previous();
    Expression* right = equality();
    expr = new Logical(expr, op, right);
  }

  return expr;
}

Token Parser::previous() {
  return tokens[current - 1];
}

bool Parser::match(std::vector<TokenType> types) {
  for (TokenType type : types) {
    if (check(type)) {
      advance();
      return true;
    }
  }
  return false;
}

Token Parser::advance() {
  if (!isAtEnd())
    current++;
  return previous();
}

bool Parser::check(TokenType type) {
  if (isAtEnd())
    return false;
  return peek().type == type;
}

bool Parser::isAtEnd() {
  return peek().type == TokenType::END_OF_FILE;
}

Token Parser::peek() {
  return tokens[current];
}

Token Parser::consume(TokenType type, std::string message) {
  if (check(type))
    return advance();

  throw error(peek(), message);
}

ParseError Parser::error(Token token,
                         std::string message) {  // @TODO : Move to ErrorHandler
  CRIT << "[line " << token.line << "] Error" << message << ENDL;
  return ParseError(message);
}

void Parser::synchronize() {
  advance();

  while (!isAtEnd()) {
    if (previous().type == TokenType::SEMICOLON)
      return;

    switch (peek().type) {
      case TokenType::CLASS:
      case TokenType::DEF:
      case TokenType::VAR:
      case TokenType::FOR:
      case TokenType::IF:
      case TokenType::WHILE:
      case TokenType::PRINT:
      case TokenType::RETURN:
        return;
      default:
        break;
    }

    advance();
  }
}

Statement* Parser::function(std::string kind) {
  Token name = consume(TokenType::IDENTIFIER, "Expect " + kind + " name.");

  consume(TokenType::LEFT_PAREN, "Expect '(' after " + kind + " name.");
  std::vector<Token> params;

  if (!check(TokenType::RIGHT_PAREN)) {
    do {
      if (params.size() >= 64) {
        error(peek(), "Function definitions cannot have more than 64 parameters.");
      }
      params.push_back(consume(TokenType::IDENTIFIER, "Expect parameter name."));
    } while (match({TokenType::COMMA}));
  }

  consume(TokenType::RIGHT_PAREN, "Expect ')' after parameters.");

  consume(TokenType::LEFT_BRACE, "Expect '{' before " + kind + " body.");
  std::vector<Statement*> body = block();
  return new FunctionStatement(name, params, body);
}

Statement* Parser::varDeclaration() {
  Token name = consume(TokenType::IDENTIFIER, "Expect variable name.");

  Expression* initializer = nullptr;
  if (match({TokenType::EQUAL})) {
    initializer = expression();
  }

  consume(TokenType::SEMICOLON, "Expect ';' after variable declaration.");
  return new VarStatement(name, initializer);
}

Expression* Parser::finishCall(Expression* callee) {
  std::vector<Expression*> arguments;
  if(!check(TokenType::RIGHT_PAREN)) {
    do {
      if (arguments.size() >= 64) {
        error(peek(), "Function definitions cannot have more than 64 arguments.");
      }
      arguments.push_back(expression());
    } while (match({TokenType::COMMA}));
  }

  Token paren = consume(TokenType::RIGHT_PAREN, "Expect ')' after arguments.");

  return new Call(callee, paren, arguments);
}

Expression* Parser::parseExpression() {
  try {
    return expression();
  } catch (const ParseError& e) {
    CRIT << "Parse error: " << e.what() << ENDL;
    return nullptr;
  }
}

std::vector<Statement*> Parser::parse() {
  std::vector<Statement*> statements;

  while (!isAtEnd()) {
    statements.push_back(declaration());
  }

  return statements;
}

Statement* Parser::statement() {
  if (match({TokenType::FOR})) {
    return forStatement();
  } else if (match({TokenType::IF})) {
    return ifStatement();
  } else if (match({TokenType::WHILE})) {
    return whileStatement();
  } else if (match({TokenType::PRINT})) {
    return printStatement();
  } else if (match({TokenType::LEFT_BRACE})) {
    return new BlockStatement(block());
  } else if (match({TokenType::RETURN})) {
    Token keyword = previous();
    Expression* value = nullptr;
    if (!check(TokenType::SEMICOLON)) {
      value = expression();
    }
    consume(TokenType::SEMICOLON, "Expect ';' after return value.");
    
    return new ReturnStatement(keyword, value);
  }
  
  return expressionStatement();
}

std::vector<Statement*> Parser::block() {
  std::vector<Statement*> statements;

  while (!check(TokenType::RIGHT_BRACE) && !isAtEnd()) {
    statements.push_back(declaration());
  }

  consume(TokenType::RIGHT_BRACE, "Expect '}' after block.");
  return statements;
}

Statement* Parser::printStatement() {
  Expression* value = expression();
  consume(TokenType::SEMICOLON, "Expect ';' after value.");
  return new PrintStatement(value);
}

Statement* Parser::ifStatement() {
  consume(TokenType::LEFT_PAREN, "Expect '(' after 'if'.");
  Expression* condition = expression();
  consume(TokenType::RIGHT_PAREN, "Expect ')' after if condition.");

  Statement* thenBranch = statement();
  Statement* elseBranch = nullptr;
  if (match({TokenType::ELSE})) {
    elseBranch = statement();
  }

  return new IfStatement(condition, thenBranch, elseBranch);
}

Statement* Parser::whileStatement() {
  consume(TokenType::LEFT_PAREN, "Expect '(' after 'while'.");
  Expression* condition = expression();
  consume(TokenType::RIGHT_PAREN, "Expect ')' after condition.");
  Statement* body = statement();

  return new WhileStatement(condition, body);
}

Statement* Parser::forStatement() {
  consume(TokenType::LEFT_PAREN, "Expect '(' after 'for'.");

  Statement* initializer = nullptr;
  if (match({TokenType::SEMICOLON})) {
    initializer = nullptr;
  } else if (match({TokenType::VAR})) {
    initializer = varDeclaration();
  } 
  else {
    initializer = expressionStatement();
  }

  Expression* condition = nullptr;
  if (!check(TokenType::SEMICOLON)) {
    condition = expression();
  }
  consume(TokenType::SEMICOLON, "Expect ';' after loop condition.");

  Expression* increment = nullptr;
  if (!check(TokenType::RIGHT_PAREN)) {
    increment = expression();
  }
  consume(TokenType::RIGHT_PAREN, "Expect ')' after for clauses.");

  Statement* body = statement();

  // Desugar increment: if increment is non-null, append it to the end of the loop body
  if (increment != nullptr) {
    body = new BlockStatement({body, new ExpressionStatement(increment)});
  }

  // Desugar condition: if condition is null, set it to `true`
  if (condition == nullptr) {
    condition = new LiteralBool(true);
  }
  
  // Create the loop using the while statement with the desugared condition
  body = new WhileStatement(condition, body);

  // Desugar initializer: if initializer is non-null, wrap everything in a new block with the initializer
  if (initializer != nullptr) {
    body = new BlockStatement({initializer, body});
  }

  return body;
}


Statement* Parser::expressionStatement() {
  Expression* expr = expression();
  consume(TokenType::SEMICOLON, "Expect ';' after expression.");
  return new ExpressionStatement(expr);
}