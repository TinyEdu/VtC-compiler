#include "Token.h"

// Constructor definition
Token::Token(TokenType type, std::string lexeme, std::string literal, int line)
    : type(type), lexeme(std::move(lexeme)), literal(std::move(literal)), line(line) {}

// Destructor definition
Token::~Token() {}


std::ostream& operator<<(std::ostream& os, const Token& token) {
    os << tokenTypeMap.at(token.type) << " " << token.lexeme << " " << token.literal << " " << token.line;
    return os;
}
