// Token.h

#ifndef TOKEN_H
#define TOKEN_H

#include <iomanip>
#include <iostream>
#include <string>
#include <utility>
#include <format>

#include "TokenType.h"
#include "TokenTypeMappings.h"

class Token {
public:
    Token(const TokenType type, std::string lexeme, std::string literal, const int line);
    Token(const TokenType type);
    ~Token();

    friend std::ostream& operator<<(std::ostream& os, const Token& token);

    bool operator==(const Token& other) const {
        return type == other.type && lexeme == other.lexeme && literal == other.literal && line == other.line;
    }

    TokenType type;
    std::string lexeme;
    std::string literal;
    int line;
    std::string lexeme_;
};

#endif  // TOKEN_H