// Scanner.h
#ifndef TEXT_SCANNER_H
#define TEXT_SCANNER_H

#if defined(VTC_TEXT_SCANNER_EXPORTS)
#  if defined(_WIN32)
#    define VTC_TEXT_SCANNER_API __declspec(dllexport)
#  else
#    define VTC_TEXT_SCANNER_API __attribute__((visibility("default")))
#  endif
#else
#  define VTC_TEXT_SCANNER_API __declspec(dllimport)
#endif

#include <string>
#include <vector>

#include "Token/Token.h"

class VTC_TEXT_SCANNER_API TextScanner
{
public:
    TextScanner() = default;

    std::vector<Token> scan(std::string_view inputSource);
    void reset();

private:
    int startIndex = 0;
    int currentIndex = 0;
    int lineNumber = 1;

    static bool isSingleCharacterToken(char c);
    bool isDoubleCharacterTokens(char c, TokenType& tokenType);

    [[nodiscard]] bool isAtEnd() const;
    [[nodiscard]] bool isComment(char c) const;
    [[nodiscard]] static bool isWhitespace(char c);
    [[nodiscard]] static bool isNewLine(char c);
    [[nodiscard]] static bool isStartingString(char c);
    [[nodiscard]] static bool isDigit(char c);
    [[nodiscard]] static bool isAlphabetic(char c);
    [[nodiscard]] static bool isAlphanumeric(char c);

    void scanToken();
    char getNextChar();
    void addToken(TokenType tokenType);
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
