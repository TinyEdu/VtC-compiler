// Parser.h

#ifndef PARSER_H
#define PARSER_H

#include <stdexcept>
#include <vector>

#include "Token.h"
#include "LogManager.h"


// Forward declaration of Expression classes
class Expression;

class Binary;
class Grouping;
class Literal;
class Unary;


class ParseError : public std::runtime_error {
 public:
  ParseError(std::string message) : std::runtime_error(message) {}
};

class Parser {
 private:
  std::vector<Token> tokens;
  int current = 0;

 public:
  Parser(std::vector<Token> tokens);
  ~Parser();

 private:
  Expression* expression();
  Expression* equality();
  Expression* comparison();
  Expression* term();
  Expression* factor();
  Expression* unary();
  Expression* primary();

  Token previous();
  bool match(std::vector<TokenType> types);
  Token advance();
  bool check(TokenType type);
  bool isAtEnd();
  Token peek();
  Token consume(TokenType type, std::string message);
  ParseError error(Token token, std::string message);
  void synchronize();

 public:
  Expression* parse();
};

#endif  // PARSER_H