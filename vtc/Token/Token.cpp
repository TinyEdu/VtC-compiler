// Token.cpp
#include "Token.h"

#include <format>
#include "TokenTypeMappings.h"

Token::Token(const TokenType type, std::string lexeme, std::string literal, const int line)
    : type(type), lexeme(std::move(lexeme)), literal(std::move(literal)), line(line)
{
}

Token::Token(const TokenType type)
{
    this->type = type;
    this->lexeme = "";
    this->literal = "";
    this->line = 0;
}

Token::~Token() = default;

bool Token::operator==(const Token& other) const
{
    return type == other.type && lexeme == other.lexeme && literal == other.literal && line == other.line;
}

std::ostream& operator<<(std::ostream& os, const Token& token)
{
    constexpr int typeWidth = 15;
    constexpr int lexemeWidth = 15;
    constexpr int literalWidth = 15;
    constexpr int lineWidth = 5;

    // Create a formatted string
    const std::string formatted = std::format("{:<{}}{:<{}}{:<{}}{:<{}}",
                                              tokenTypeMap.at(token.type), typeWidth,
                                              token.lexeme, lexemeWidth,
                                              token.literal, literalWidth,
                                              token.line, lineWidth);

    // Output the formatted string to the stream
    os << formatted;
    return os;
}
