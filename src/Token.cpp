// Token.cpp
#include "Token.h"

// Constructor definition
Token::Token(TokenType type, std::string lexeme, std::string literal, int line)
    : type(type),
      lexeme(lexeme),
      literal(literal),
      line(line) {}

Token::Token(TokenType type) {
  this->type = type;
  this->lexeme = "";
  this->literal = "";
  this->line = 0;
}

// Destructor definition
Token::~Token() {}

std::ostream& operator<<(std::ostream& os, const Token& token) {
  const int typeWidth = 15;
  const int lexemeWidth = 15;
  const int literalWidth = 15;
  const int lineWidth = 5;

  os << std::left << std::setw(typeWidth) << tokenTypeMap.at(token.type)
     << std::left << std::setw(lexemeWidth) << token.lexeme << std::left
     << std::setw(literalWidth) << token.literal << std::left
     << std::setw(lineWidth) << token.line;

  return os;
}
