// Parser.h

#ifndef PARSER_H
#define PARSER_H

#include <stdexcept>
#include <vector>

#include "LogManager.h"
#include "Statement.h"
#include "Token.h"

// Forward declaration of Expression classes
class Expression;

class Binary;
class Grouping;
class Literal;
class Unary;

class Statement;

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
  Statement* declaration();
  Expression* assignment();
  Expression* expression();
  Expression* equality();
  Expression* comparison();
  Expression* term();
  Expression* factor();
  Expression* unary();
  Expression* call();
  Expression* primary();

  // logical
  Expression* logicalOr();
  Expression* logicalAnd();

  Token previous();
  bool match(std::vector<TokenType> types);
  Token advance();
  bool check(TokenType type);
  bool isAtEnd();
  Token peek();
  Token consume(TokenType type, std::string message);
  ParseError error(Token token, std::string message);
  void synchronize();
  Statement* function(std::string kind);
  Statement* varDeclaration();
  Expression* finishCall(Expression* callee);


 public:
  Expression* parseExpression();
  std::vector<Statement*> parse();
  Statement* expressionStatement();
  Statement* printStatement();
  Statement* ifStatement();
  Statement* whileStatement();
  Statement* forStatement();
  Statement* statement();
  std::vector<Statement*> block();
};

#endif  // PARSER_H