// Scanner.h

#ifndef SCANNER_H
#define SCANNER_H

#include <sstream>
#include <string>
#include <utility>
#include <vector>
#include <unordered_set>

#include "ErrorHandler.h"
#include "LogManager/LogManager.h"
#include "Token/Token.h"

class Scanner
{
public:
    Scanner() = default;

    std::vector<Token> scan(std::string_view inputSource);
    void reset();

private:
    int startIndex = 0;
    int currentIndex = 0;
    int lineNumber = 1;

    bool isSingleCharacterToken(char c);
    bool isDoubleCharacterTokens(char c, TokenType& tokenType);

    [[nodiscard]] bool isAtEnd() const;
    [[nodiscard]] bool isWhitespace(char c) const;
    [[nodiscard]] bool isComment(char c) const;
    [[nodiscard]] bool isNewLine(char c);
    [[nodiscard]] bool isStartingString(char c);
    [[nodiscard]] bool isDigit(char c) const;
    [[nodiscard]] bool isAlphabetic(char c) const;
    [[nodiscard]] bool isAlphanumeric(char c) const;

    void scanToken();
    char advance();
    void addToken(TokenType type);
    void addToken(TokenType type, const std::string& literal);

    [[nodiscard]] bool match(char expected);

    [[nodiscard]] char peek() const;
    [[nodiscard]] char peekNext() const;

    bool handleLiterals(char c);
    void handleStringLiteral();
    void handleNumberLiteral();
    void handleIdentifierLiteral();

    std::string source;
    std::vector<Token> tokens;
};

#endif  // SCANNER_H
