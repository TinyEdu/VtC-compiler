// Scanner.h
#ifndef SCANNER_H
#define SCANNER_H

#include <string>
#include <vector>
#include "Token.h"
#include "ErrorHandler.h"

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

    std::string source;
    std::vector<Token> tokens;
};

#endif // SCANNER_H
