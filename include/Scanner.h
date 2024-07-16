// Scanner.h
#ifndef SCANNER_H
#define SCANNER_H

#include <sstream>
#include <string>
#include <vector>
#include "ErrorHandler.h"
#include "Token.h"

class Scanner {
 public:
  // Constructor
  Scanner(const std::string& source) : source(source) {}

  std::vector<Token> scanTokens();

 private:
  int start = 0;
  int end = 0;
  int line = 1;
  int current = 0;

  bool isAtEnd() const;
  void scanToken();
  char advance();
  void addToken(TokenType type);
  void addToken(TokenType type, const std::string& literal);
  bool match(char expected);
  char peek() const;
  char peekNext() const;
  void stringLiteral();
  void numberLiteral();
  bool isDigit(char c) const;
  bool isAlpha(char c) const;
  bool isAlphanumeric(char c) const;

  void identifier();

  std::string source;
  std::vector<Token> tokens;
};

#endif  // SCANNER_H
