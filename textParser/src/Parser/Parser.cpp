// Parser.cpp
#include "Parser.h"

#include <utility>
#include "Expressions/ExpressionsWorld.h"
#include "Statements/StatementsWorld.h"
#include "LogManager/LogManager.h"

Parser::Parser(std::vector<Token> tokens) : ParserBase(std::move(tokens))
{
}

Parser::~Parser() = default;

std::vector<std::shared_ptr<Statement>> Parser::parse()
{
    std::vector<std::shared_ptr<Statement>> statements;

    while (!isAtEnd())
    {
        statements.push_back(declaration());
    }

    return statements;
}

// ----------------------------------------------------------------------------------------------

std::shared_ptr<Statement> Parser::declaration()
{
    try
    {
        if (match(TokenType::VAR))
        {
            return varDeclaration();
        }

        if (match(TokenType::DEF))
        {
            return functionDeclaration("function");
        }

        return statementDeclaration();
    }
    catch (const ParseError& e)
    {
        CRIT() << "Parse error: " << e.what();
        synchronize();
        return nullptr;
    }
}

std::shared_ptr<Expression> Parser::expression()
{
    return assignment();
}

std::shared_ptr<Expression> Parser::assignment()
{
    auto expr = logicalOr();

    if (match(TokenType::EQUAL))
    {
        const Token equals = previous();
        auto value = assignment();

        if (auto varExpr = std::dynamic_pointer_cast<Variable>(expr))
        {
            return std::make_shared<Assign>(varExpr->name, value);
        }

        error(equals, "Invalid assignment target.");
    }

    return expr;
}

std::shared_ptr<Expression> Parser::equality()
{
    auto expr = comparison();

    while (match({TokenType::BANG_EQUAL, TokenType::EQUAL_EQUAL}))
    {
        const Token op = previous();
        auto right = comparison();

        expr = std::make_shared<Binary>(expr, op, right);
    }

    return expr;
}

std::shared_ptr<Expression> Parser::comparison()
{
    auto expr = term();

    while (match({TokenType::GREATER, TokenType::GREATER_EQUAL, TokenType::LESS, TokenType::LESS_EQUAL}))
    {
        const Token op = previous();
        auto right = term();

        expr = std::make_shared<Binary>(expr, op, right);
    }

    return expr;
}

std::shared_ptr<Expression> Parser::term()
{
    auto expr = factor();

    while (match({TokenType::MINUS, TokenType::PLUS}))
    {
        const Token op = previous();
        auto right = factor();

        expr = std::make_shared<Binary>(expr, op, right);
    }

    return expr;
}

std::shared_ptr<Expression> Parser::factor()
{
    auto expr = unary();

    while (match({TokenType::SLASH, TokenType::STAR}))
    {
        const Token op = previous();
        auto right = unary();

        expr = std::make_shared<Binary>(expr, op, right);
    }

    return expr;
}

std::shared_ptr<Expression> Parser::unary()
{
    if (match({TokenType::BANG, TokenType::MINUS}))
    {
        const Token op = previous();
        auto right = unary();

        return std::make_shared<Unary>(op, right);
    }
    return call();
}

std::shared_ptr<Expression> Parser::call()
{
    auto expr = primary();

    while (true)
    {
        if (match(TokenType::LEFT_PAREN))
        {
            expr = finishCallDeclaration(expr);
        }
        else
        {
            break;
        }
    }

    return expr;
}

std::shared_ptr<Expression> Parser::primary()
{
    if (match(TokenType::FALSE)) return std::make_shared<LiteralBool>(false);
    if (match(TokenType::TRUE)) return std::make_shared<LiteralBool>(true);
    if (match(TokenType::NIL)) return std::make_shared<LiteralInt>(0); // Handle null appropriately
    if (match(TokenType::NUMBER))
    {
        if (previous().literal.find('.') != std::string::npos)
        {
            return std::make_shared<LiteralDouble>(std::stod(previous().literal));
        }
        return std::make_shared<LiteralInt>(std::stoi(previous().literal));
    }
    if (match(TokenType::STRING)) return std::make_shared<LiteralString>(previous().literal);
    if (match(TokenType::LEFT_PAREN))
    {
        auto expr = expression();
        consume(TokenType::RIGHT_PAREN, "Expect ')' after expression.");
        return std::make_shared<Grouping>(expr);
    }
    if (match(TokenType::IDENTIFIER)) return std::make_shared<Variable>(previous());

    throw ParseError("Expect expression.");
}

// ----------------------------------------------------------------------------------------------

std::shared_ptr<Statement> Parser::varDeclaration()
{
    const Token name = consume(TokenType::IDENTIFIER, "Expect variable name.");
    auto initializer = match(TokenType::EQUAL) ? expression() : nullptr;
    consume(TokenType::SEMICOLON, "Expect ';' after variable declaration.");
    return std::make_shared<VarStatement>(name, initializer);
}

std::shared_ptr<Statement> Parser::statementDeclaration()
{
    if (match(TokenType::FOR)) return forStatement();
    if (match(TokenType::IF)) return ifStatement();
    if (match(TokenType::WHILE)) return whileStatement();
    if (match(TokenType::PRINT)) return printStatement();
    if (match(TokenType::LEFT_BRACE)) return std::make_shared<BlockStatement>(parseBlock());
    if (match(TokenType::RETURN))
    {
        const Token keyword = previous();
        auto value = !check(TokenType::SEMICOLON) ? expression() : nullptr;
        consume(TokenType::SEMICOLON, "Expect ';' after return value.");
        return std::make_shared<ReturnStatement>(keyword, value);
    }

    return expressionStatement();
}

std::shared_ptr<Statement> Parser::functionDeclaration(const std::string& kind)
{
    const Token name = consume(TokenType::IDENTIFIER, "Expect " + kind + " name.");
    consume(TokenType::LEFT_PAREN, "Expect '(' after " + kind + " name.");

    std::vector<Token> params;
    if (!check(TokenType::RIGHT_PAREN))
    {
        do
        {
            if (params.size() >= 64) error(peek(), "Cannot have more than 64 parameters.");
            params.push_back(consume(TokenType::IDENTIFIER, "Expect parameter name."));
        }
        while (match(TokenType::COMMA));
    }

    consume(TokenType::RIGHT_PAREN, "Expect ')' after parameters.");
    consume(TokenType::LEFT_BRACE, "Expect '{' before " + kind + " body.");
    auto body = parseBlock();

    return std::make_shared<FunctionStatement>(name, params, body);
}

std::shared_ptr<Expression> Parser::finishCallDeclaration(std::shared_ptr<Expression> callee)
{
    std::vector<std::shared_ptr<Expression>> arguments;
    if (!check(TokenType::RIGHT_PAREN))
    {
        do
        {
            if (arguments.size() >= 64) error(peek(), "Cannot have more than 64 arguments.");
            arguments.push_back(expression());
        }
        while (match(TokenType::COMMA));
    }

    const Token paren = consume(TokenType::RIGHT_PAREN, "Expect ')' after arguments.");
    return std::make_shared<Call>(callee, paren, arguments);
}

std::shared_ptr<Statement> Parser::printStatement()
{
    auto value = expression();
    consume(TokenType::SEMICOLON, "Expect ';' after value.");
    return std::make_shared<PrintStatement>(value);
}

std::shared_ptr<Statement> Parser::ifStatement()
{
    consume(TokenType::LEFT_PAREN, "Expect '(' after 'if'.");
    auto condition = expression();
    consume(TokenType::RIGHT_PAREN, "Expect ')' after if condition.");
    auto thenBranch = statementDeclaration();
    auto elseBranch = match(TokenType::ELSE) ? statementDeclaration() : nullptr;

    return std::make_shared<IfStatement>(condition, thenBranch, elseBranch);
}

std::shared_ptr<Statement> Parser::whileStatement()
{
    consume(TokenType::LEFT_PAREN, "Expect '(' after 'while'.");
    auto condition = expression();
    consume(TokenType::RIGHT_PAREN, "Expect ')' after condition.");
    auto body = statementDeclaration();

    return std::make_shared<WhileStatement>(condition, body);
}

std::shared_ptr<Statement> Parser::forStatement()
{
    consume(TokenType::LEFT_PAREN, "Expect '(' after 'for'.");
    auto initializer = match(TokenType::SEMICOLON) ? nullptr :
    (match(TokenType::VAR) ? varDeclaration() : expressionStatement());
    auto condition = !check(TokenType::SEMICOLON) ? expression() : nullptr;
    consume(TokenType::SEMICOLON, "Expect ';' after loop condition.");
    auto increment = !check(TokenType::RIGHT_PAREN) ? expression() : nullptr;
    consume(TokenType::RIGHT_PAREN, "Expect ')' after for clauses.");
    auto body = statementDeclaration();

    if (increment)
    {
        body = std::make_shared<BlockStatement>(std::vector<std::shared_ptr<Statement>>{
            body, std::make_shared<ExpressionStatement>(increment)
        });
    }

    if (!condition)
    {
        condition = std::make_shared<LiteralBool>(true);
    }

    body = std::make_shared<WhileStatement>(condition, body);

    if (initializer)
    {
        body = std::make_shared<BlockStatement>(std::vector<std::shared_ptr<Statement>>{initializer, body});
    }

    return body;
}

std::shared_ptr<Statement> Parser::expressionStatement()
{
    auto expr = expression();
    consume(TokenType::SEMICOLON, "Expect ';' after expression.");
    return std::make_shared<ExpressionStatement>(expr);
}

std::shared_ptr<Expression> Parser::logicalOr()
{
    auto expr = logicalAnd();

    while (match(TokenType::OR))
    {
        const Token op = previous();
        auto right = logicalAnd();
        expr = std::make_shared<Logical>(expr, op, right);
    }

    return expr;
}

std::shared_ptr<Expression> Parser::logicalAnd()
{
    auto expr = equality();

    while (match(TokenType::AND))
    {
        const Token op = previous();
        auto right = equality();
        expr = std::make_shared<Logical>(expr, op, right);
    }

    return expr;
}

std::vector<std::shared_ptr<Statement>> Parser::parseBlock()
{
    std::vector<std::shared_ptr<Statement>> statements;

    while (!check(TokenType::RIGHT_BRACE) && !isAtEnd())
    {
        statements.push_back(declaration());
    }

    consume(TokenType::RIGHT_BRACE, "Expect '}' after block.");
    return statements;
}
