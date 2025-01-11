// Scanner.cpp
#include "Scanner.h"
#include "Token/TokenTypeMappings.h"

static const std::unordered_set validChars = {
    '(', ')', '{', '}', ',', '.', '-', '+', ';', '*', '/', '<', '>', '=', '!'
};

std::vector<Token> Scanner::scan(const std::string_view inputSource)
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

void Scanner::reset()
{
    currentIndex = 0;
    startIndex = 0;
    lineNumber = 1;
    tokens.clear();
}

bool Scanner::isAtEnd() const
{
    return currentIndex == source.length();
}

bool Scanner::isNewLine(const char c)
{
    return c == '\n';
}


bool Scanner::isStartingString(const char c)
{
    return c == '"';
}

bool Scanner::handleLiterals(const char c)
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

void Scanner::scanToken()
{
    using enum TokenType;

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
    LogManager::crit() << "Error: Unexpected character '" << c << "' at line " << lineNumber << "\n";
    ErrorHandler::error(lineNumber, "invalid character");
}

bool Scanner::isWhitespace(const char c)
{
    return (c == '\r' || c == '\t' || c == ' ' || c == '\0');
}

bool Scanner::isComment(const char c) const
{
    return (c == '/' && peek() == '/');
}

bool Scanner::isSingleCharacterToken(const char c)
{
    return validChars.contains(c);
}

bool Scanner::isDoubleCharacterTokens(const char c, TokenType& tokenType)
{
    using enum TokenType;

    // Check if the character is part of a double-character token
    if (const auto it = doubleCharTokensMappings.find(c); it != doubleCharTokensMappings.end() && match('='))
    {
        switch (c)
        {
        case '!': tokenType = BANG_EQUAL;
            break;
        case '=': tokenType = EQUAL_EQUAL;
            break;
        case '<': tokenType = LESS_EQUAL;
            break;
        case '>': tokenType = GREATER_EQUAL;
            break;
        default: tokenType = INVALID;
        }

        return true;
    }

    return false;
}

char Scanner::getNextChar()
{
    return source[currentIndex++];
}

void Scanner::addToken(const TokenType tokenType)
{
    addToken(tokenType, "");
}

void Scanner::addToken(TokenType type, const std::string& literal)
{
    std::string text = source.substr(startIndex, currentIndex - startIndex);
    tokens.emplace_back(type, text, literal, lineNumber);
}

bool Scanner::match(const char expected)
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

char Scanner::peek() const
{
    if (isAtEnd())
    {
        return '\0';
    }

    return source[currentIndex];
}

char Scanner::peekNext() const
{
    if (currentIndex + 1 >= source.length())
    {
        return '\0';
    }

    return source[currentIndex + 1];
}

void Scanner::handleStringLiteral()
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

void Scanner::handleNumberLiteral()
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

bool Scanner::isDigit(const char c)
{
    return c >= '0' && c <= '9';
}

bool Scanner::isAlphabetic(const char c)
{
    return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == '_');
}

bool Scanner::isAlphanumeric(const char c)
{
    return isAlphabetic(c) || isDigit(c);
}

void Scanner::handleIdentifierLiteral()
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
