#include "ParserBase.h"


#include <memory>
#include <utility>
#include <algorithm>

#include "Expressions/ExpressionsWorld.h"
#include "Statements/StatementsWorld.h"
#include "LogManager/LogManager.h"
#include "Token/TokenTypeMappings.h"
#include "Token/TokenType.h"
#include "Statements/Statement.h"

ParserBase::ParserBase(std::vector<Token> tokens) : tokens(std::move(tokens))
{
}

ParserBase::~ParserBase() = default;

Token ParserBase::previous()
{
    return tokens[currentIndex - 1];
}

bool ParserBase::match(const std::vector<TokenType>& types)
{
    return std::any_of(types.begin(), types.end(), [this](const TokenType& type)
    {
        return match(type);
    });
}

bool ParserBase::match(const TokenType type)
{
    if (check(type))
    {
        advance();
        return true;
    }

    return false;
}

Token ParserBase::advance()
{
    if (!isAtEnd())
    {
        currentIndex++;
    }

    return previous();
}

bool ParserBase::check(const TokenType type)
{
    if (isAtEnd())
    {
        return false;
    }

    return peek().type == type;
}

bool ParserBase::isAtEnd()
{
    return peek().type == TokenType::END_OF_FILE;
}

Token ParserBase::peek()
{
    return tokens[currentIndex];
}

Token ParserBase::consume(const TokenType type, const std::string& message)
{
    if (check(type))
    {
        return advance();
    }

    throw error(peek(), message);
}

ParseError ParserBase::error(const Token& token, const std::string& message)
{
    CRIT() << "[line " << token.line << "] Error" << message;
    return ParseError(message);
}

void ParserBase::synchronize()
{
    advance();

    while (!isAtEnd())
    {
        if (previous().type == TokenType::SEMICOLON)
        {
            return;
        }

        switch (peek().type)
        {
        case TokenType::CLASS:
        case TokenType::DEF:
        case TokenType::VAR:
        case TokenType::FOR:
        case TokenType::IF:
        case TokenType::WHILE:
        case TokenType::PRINT:
        case TokenType::RETURN:
            return;
        default:
            break;
        }

        advance();
    }
}
