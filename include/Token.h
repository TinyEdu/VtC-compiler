#ifndef TOKEN_H
#define TOKEN_H

#include <string>
#include <iostream>

#include "TokenType.h"


class Token {
public:
    Token(TokenType type, std::string lexeme, std::string literal, int line);
    ~Token();

    friend std::ostream& operator<<(std::ostream& os, const Token& token);
public:
    TokenType type;
    std::string lexeme;
    std::string literal;
    int line;
};

#endif // TOKEN_H