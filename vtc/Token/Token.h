// Token.h

#ifndef TOKEN_H
#define TOKEN_H

#include <string>

#include "TokenType.h"

class Token
{
public:
    explicit Token(TokenType type);
    Token(TokenType type, std::string lexeme, std::string literal, int line);
    /**
     * Constructor to initialize a Token with all its attributes.
     * @param type The type of the token.
     * @param lexeme The raw text in the source code that this token represents.
     * @param literal The parsed value of the token (e.g., the actual number for a numeric literal).
     * @param line The line number in the source code where the token appears.
     */
    ~Token();

    friend std::ostream& operator<<(std::ostream& os, const Token& token);

    bool operator==(const Token& other) const;

    TokenType type;
    std::string lexeme;
    std::string literal;

    int line;
};

#endif  // TOKEN_H
