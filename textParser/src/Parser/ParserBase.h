#ifndef PARSERBASE_H
#define PARSERBASE_H

#include <vector>
#include "Token/Token.h"
#include "ParseError.h"

class ParserBase
{
public:
    explicit ParserBase(std::vector<Token> tokens);
    ~ParserBase();

protected:
    std::vector<Token> tokens;
    int currentIndex = 0;


    Token previous();
    bool match(const std::vector<TokenType>& types);
    bool match(TokenType type);
    Token advance();
    bool check(TokenType type);
    bool isAtEnd();
    Token peek();
    Token consume(TokenType type, const std::string& message);
    static ParseError error(const Token& token, const std::string& message);
    void synchronize();
};

#endif  // PARSERBASE_H
