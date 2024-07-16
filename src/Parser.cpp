#include "Parser.h"

Parser::Parser(std::vector<Token> tokens)
    : tokens(tokens)
{
}

Parser::~Parser()
{
}


Expression* Parser::expression() {
    try {
        return equality();
    } catch (const ParseError& e) {
        // Handle the error, maybe log it or propagate further
        std::cerr << "Parse error: " << e.what() << std::endl;
        return nullptr;  // Or handle it in a way that makes sense for your application
    }
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

    while (match({TokenType::GREATER, TokenType::GREATER_EQUAL, TokenType::LESS, TokenType::LESS_EQUAL})) {
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
    Expression *expr = unary();

    while (match({TokenType::SLASH, TokenType::STAR}))
    {
        Token op = previous();
        Expression *right = unary();
        expr = new Binary(expr, op, right);
    }
    
    return expr;
}

Expression* Parser::unary() {
    Expression* expr = primary();
    if (match({TokenType::BANG, TokenType::MINUS})) {
        Token op = previous();
        Expression* right = unary();
        return new Unary(op, right);
    }

  return primary();
}

Expression* Parser::primary() {
    if (match({TokenType::FALSE})) return new Literal(false);
    if (match({TokenType::TRUE})) return new Literal(true);
    if (match({TokenType::NIL})) return new Literal(nullptr);

    if (match({TokenType::NUMBER, TokenType::STRING})) {
        return new Literal(previous().literal);
    }

    if (match({TokenType::LEFT_PAREN})) {
        Expression* expr = expression();
        if (!match({TokenType::RIGHT_PAREN})) {
            throw ParseError("Expect ')' after expression.");
        }
        return new Grouping(expr);
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
    if (!isAtEnd()) current++;
    return previous();
}

bool Parser::check(TokenType type) {
    if (isAtEnd()) return false;
    return peek().type == type;
}

bool Parser::isAtEnd() {
  return peek().type == TokenType::END_OF_FILE;
}

Token Parser::peek() {
  return tokens[current];
}

Token Parser::consume(TokenType type, std::string message) {
    if (check(type)) return advance();
    throw error(peek(), message);
}

ParseError Parser::error(Token token, std::string message) {
    std::cerr << "[line " << token.line << "] Error" << message << std::endl;
    return ParseError(message);
}

void Parser::synchronize() {
    advance();

    while (!isAtEnd()) {
        if (previous().type == TokenType::SEMICOLON) return;

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

Expression* Parser::parse() {
    try {
        return expression();
    } catch (const ParseError& e) {
        // Handle the error, maybe log it or propagate further
        std::cerr << "Parse error: " << e.what() << std::endl;
        return nullptr;  // Or handle it in a way that makes sense for your application
    }
}
