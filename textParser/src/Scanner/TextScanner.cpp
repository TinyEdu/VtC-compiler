// Scanner.cpp
#include "TextScanner.h"

#include <unordered_set>

#include "ErrorHandler.h"
#include "Token/TokenTypeMappings.h"

static const std::unordered_set validChars = {
    '(', ')', '{', '}', ',', '.', '-', '+', ';', '*', '/', '<', '>', '=', '!'
};

std::vector<Token> TextScanner::scan(const std::string_view inputSource)
{
    reset();
    source = inputSource;

    while (!isAtEnd())
    {
        // We are at the beginning of the next lexeme
        startIndex = currentIndex;
        scanToken();
    }

    tokens.emplace_back(TokenType::END_OF_FILE, "", "", lineNumber);

    return tokens;
}

void TextScanner::reset()
{
    currentIndex = 0;
    startIndex = 0;
    lineNumber = 1;
    tokens.clear();
}

bool TextScanner::isAtEnd() const
{
    return currentIndex == source.length();
}

bool TextScanner::isNewLine(const char c)
{
    return c == '\n';
}


bool TextScanner::isStartingString(const char c)
{
    return c == '"';
}

bool TextScanner::handleLiterals(const char c)
{
    if (isStartingString(c))
    {
        // "striiing"
        handleStringLiteral();
        return true;
    }

    if (isDigit(c))
    {
        // 12345678.0
        handleNumberLiteral();
        return true;
    }

    if (isAlphabetic(c))
    {
        // variable_name
        handleIdentifierLiteral();
        return true;
    }

    // If no literals are found, return false
    return false;
}

void TextScanner::scanToken()
{
    char c = getNextChar();

    if (isComment(c))
    {
        while (!isNewLine(c))
        {
            c = getNextChar();
        }
    }

    if (isWhitespace(c))
    {
        /* do nothing */
        return;
    }

    if (isNewLine(c))
    {
        lineNumber++;
        return;
    }

    // Handle two-character tokens
    if (TokenType doubleTokenType; isDoubleCharacterTokens(c, doubleTokenType))
    {
        addToken(doubleTokenType);
        return;
    }

    // Handle single-character tokens
    if (isSingleCharacterToken(c))
    {
        addToken(singleCharTokensMappings.at(c));
        return;
    }

    // Handle different types of literals
    if (handleLiterals(c))
    {
        return;
    }

    // If nothing matches, throw an error
    LOG() << "Error: Unexpected character '" << c << "' at line " << lineNumber << "\n";
    ErrorHandler::error(lineNumber, "invalid character");
}

bool TextScanner::isWhitespace(const char c)
{
    return (c == '\r' || c == '\t' || c == ' ' || c == '\0');
}

bool TextScanner::isComment(const char c) const
{
    return (c == '/' && peek() == '/');
}

bool TextScanner::isSingleCharacterToken(const char c)
{
    return validChars.find(c) != validChars.end();
}

bool TextScanner::isDoubleCharacterTokens(const char c, TokenType& tokenType)
{

    // Check if the character is part of a double-character token
    if (const auto it = doubleCharTokensMappings.find(c); it != doubleCharTokensMappings.end() && match('='))
    {
        switch (c)
        {
        case '!': tokenType = TokenType::BANG_EQUAL;
            break;
        case '=': tokenType = TokenType::EQUAL_EQUAL;
            break;
        case '<': tokenType = TokenType::LESS_EQUAL;
            break;
        case '>': tokenType = TokenType::GREATER_EQUAL;
            break;
        default: tokenType = TokenType::INVALID;
        }

        return true;
    }

    return false;
}

char TextScanner::getNextChar()
{
    return source[currentIndex++];
}

void TextScanner::addToken(const TokenType tokenType)
{
    addToken(tokenType, "");
}

void TextScanner::addToken(TokenType type, const std::string& literal)
{
    std::string text = source.substr(startIndex, currentIndex - startIndex);
    tokens.emplace_back(type, text, literal, lineNumber);
}

bool TextScanner::match(const char expected)
{
    if (isAtEnd())
    {
        return false;
    }
    if (source[currentIndex] != expected)
    {
        return false;
    }

    currentIndex++;
    return true;
}

char TextScanner::peek() const
{
    if (isAtEnd())
    {
        return '\0';
    }

    return source[currentIndex];
}

char TextScanner::peekNext() const
{
    if (currentIndex + 1 >= source.length())
    {
        return '\0';
    }

    return source[currentIndex + 1];
}

void TextScanner::handleStringLiteral()
{
    while (peek() != '"' && !isAtEnd())
    {
        if (peek() == '\n')
        {
            lineNumber++;
        }
        getNextChar();
    }

    if (isAtEnd())
    {
        ErrorHandler::error(lineNumber, "Unterminated string.");
        return;
    }

    // The closing "
    getNextChar();

    // Trim the surrounding quotes.
    const std::string value =
        source.substr(startIndex + 1, currentIndex - startIndex - 2);
    addToken(TokenType::STRING, value);
}

void TextScanner::handleNumberLiteral()
{
    while (isDigit(peek()))
    {
        getNextChar();
    }

    // Look for a fractional part.
    if (peek() == '.' && isDigit(peekNext()))
    {
        // Consume the "."
        getNextChar();

        while (isDigit(peek()))
        {
            getNextChar();
        }
    }

    const std::stringstream ss(source.substr(startIndex, currentIndex - startIndex));
    addToken(TokenType::NUMBER, ss.str());
}

bool TextScanner::isDigit(const char c)
{
    return c >= '0' && c <= '9';
}

bool TextScanner::isAlphabetic(const char c)
{
    return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == '_');
}

bool TextScanner::isAlphanumeric(const char c)
{
    return isAlphabetic(c) || isDigit(c);
}

void TextScanner::handleIdentifierLiteral()
{
    while (isAlphanumeric(peek()))
    {
        getNextChar();
    }

    const std::string text = source.substr(startIndex, currentIndex - startIndex);
    TokenType type;

    if (const auto search = keywordMappings.find(text); search != keywordMappings.end())
    {
        // There was a keyword found
        type = search->second;
    }
    else
    {
        // No keyword found --> it is an identifier
        type = TokenType::IDENTIFIER;
    }

    // If the type is not a keyword, it is an identifier
    addToken(type);
}
