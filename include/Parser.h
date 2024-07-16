#include <stdexcept>
#include <vector>
#include "Expression.h"
#include "Token.h"

class ParseError : public std::runtime_error {
 public:
  ParseError(std::string message) : std::runtime_error(message) {}
};

/*
expression     → equality ;
equality       → comparison ( ( "!=" | "==" ) comparison )* ;
comparison     → term ( ( ">" | ">=" | "<" | "<=" ) term )* ;
term           → factor ( ( "-" | "+" ) factor )* ;
factor         → unary ( ( "/" | "*" ) unary )* ;
unary          → ( "!" | "-" ) unary
               | primary ;
primary        → NUMBER | STRING | "true" | "false" | "nil"
               | "(" expression ")" ;
*/

class Parser {
 private:
  /* data */
 public:
  Parser(std::vector<Token> tokens);
  ~Parser();

  std::vector<Token> tokens;
  int current = 0;

 private:
  Expression* expression();
  Expression* equality();
  Expression* comparison();
  Expression* term();
  Expression* factor();
  Expression* unary();
  Expression* primary();

 private:
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
