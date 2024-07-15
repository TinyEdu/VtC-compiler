#include "Parser.h"

Parser::Parser(std::vector<Token> tokens)
    : tokens(tokens)
{
}

Parser::~Parser()
{
}


Expression* Parser::expression() {
    return equality();
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
        match({TokenType::RIGHT_PAREN});
        return new Grouping(expr);
    }

    return nullptr;
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
