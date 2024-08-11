// Parser.cpp
#include "Parser.h"
#include "Statement.h"
#include "Expression.h"

Parser::Parser(std::vector<Token> tokens) : tokens(tokens) {}

Parser::~Parser() {}

Statement* Parser::declaration() {
  try {
    if (match({TokenType::VAR}))
      return varDeclaration();

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
  Expression* expr = equality();

  if (match({TokenType::EQUAL})) {
    Token equals = previous();
    Expression* value = assignment();

    if (expr->type == ExpressionType::VARIABLE) {
      Token name = static_cast<Variable*>(expr)->name;
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
  return primary();
}

Expression* Parser::primary() {
  if (match({TokenType::FALSE}))
    return new Literal(false);
  else if (match({TokenType::TRUE}))
    return new Literal(true);
  else if (match({TokenType::NIL}))
    return new Literal(nullptr);
  else if (match({TokenType::NUMBER})) {
    // check if the given value is an integer or a double
    if (previous().literal.find('.') != std::string::npos) {
      return new Literal(std::stod(previous().literal));
    } else {
      return new Literal(std::stoi(previous().literal));
    }
  } else if (match({TokenType::STRING})) {
    return new Literal(previous().literal);
  } else if (match({TokenType::LEFT_PAREN})) {
    Expression* expr = expression();
    consume(TokenType::RIGHT_PAREN, "Expect ')' after expression.");
    return new Grouping(expr);
  } else if (match({TokenType::IDENTIFIER})) {
    return new Variable(previous());
  }

  throw ParseError("Expect expression.");
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

Statement* Parser::varDeclaration() {
  Token name = consume(TokenType::IDENTIFIER, "Expect variable name.");

  Expression* initializer = nullptr;
  if (match({TokenType::EQUAL})) {
    initializer = expression();
  }

  consume(TokenType::SEMICOLON, "Expect ';' after variable declaration.");
  return new VarStatement(name, initializer);
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
  if (match({TokenType::PRINT})) {
    return printStatement();
  }

  return expressionStatement();
}

Statement* Parser::printStatement() {
  Expression* value = expression();
  consume(TokenType::SEMICOLON, "Expect ';' after value.");
  return new PrintStatement(value);
}

Statement* Parser::expressionStatement() {
  Expression* expr = expression();
  consume(TokenType::SEMICOLON, "Expect ';' after expression.");
  return new ExpressionStatement(expr);
}