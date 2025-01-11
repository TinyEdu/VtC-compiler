// Parser.cpp
#include "Parser.h"

#include <utility>
#include "Expressions/ExpressionsWorld.h"
#include "Statements/StatementsWorld.h"
#include "LogManager/LogManager.h"

using enum TokenType;

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
        if (match(VAR))
        {
            return varDeclaration();
        }

        if (match(DEF))
        {
            return functionDeclaration("function");
        }

        return statementDeclaration();
    }
    catch (const ParseError& e)
    {
        LogManager::crit() << "Parse error: " << e.what();
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

    if (match(EQUAL))
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

    while (match({BANG_EQUAL, EQUAL_EQUAL}))
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

    while (match({GREATER, GREATER_EQUAL, LESS, LESS_EQUAL}))
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

    while (match({MINUS, PLUS}))
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

    while (match({SLASH, STAR}))
    {
        const Token op = previous();
        auto right = unary();

        expr = std::make_shared<Binary>(expr, op, right);
    }

    return expr;
}

std::shared_ptr<Expression> Parser::unary()
{
    if (match({BANG, MINUS}))
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
        if (match(LEFT_PAREN))
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
    if (match(FALSE)) return std::make_shared<LiteralBool>(false);
    if (match(TRUE)) return std::make_shared<LiteralBool>(true);
    if (match(NIL)) return std::make_shared<LiteralInt>(0); // Handle null appropriately
    if (match(NUMBER))
    {
        if (previous().literal.find('.') != std::string::npos)
        {
            return std::make_shared<LiteralDouble>(std::stod(previous().literal));
        }
        return std::make_shared<LiteralInt>(std::stoi(previous().literal));
    }
    if (match(STRING)) return std::make_shared<LiteralString>(previous().literal);
    if (match(LEFT_PAREN))
    {
        auto expr = expression();
        consume(RIGHT_PAREN, "Expect ')' after expression.");
        return std::make_shared<Grouping>(expr);
    }
    if (match(IDENTIFIER)) return std::make_shared<Variable>(previous());

    throw ParseError("Expect expression.");
}

// ----------------------------------------------------------------------------------------------

std::shared_ptr<Statement> Parser::varDeclaration()
{
    const Token name = consume(IDENTIFIER, "Expect variable name.");
    auto initializer = match(EQUAL) ? expression() : nullptr;
    consume(SEMICOLON, "Expect ';' after variable declaration.");
    return std::make_shared<VarStatement>(name, initializer);
}

std::shared_ptr<Statement> Parser::statementDeclaration()
{
    if (match(FOR)) return forStatement();
    if (match(IF)) return ifStatement();
    if (match(WHILE)) return whileStatement();
    if (match(PRINT)) return printStatement();
    if (match(LEFT_BRACE)) return std::make_shared<BlockStatement>(parseBlock());
    if (match(RETURN))
    {
        const Token keyword = previous();
        auto value = !check(SEMICOLON) ? expression() : nullptr;
        consume(SEMICOLON, "Expect ';' after return value.");
        return std::make_shared<ReturnStatement>(keyword, value);
    }

    return expressionStatement();
}

std::shared_ptr<Statement> Parser::functionDeclaration(const std::string& kind)
{
    const Token name = consume(IDENTIFIER, "Expect " + kind + " name.");
    consume(LEFT_PAREN, "Expect '(' after " + kind + " name.");

    std::vector<Token> params;
    if (!check(RIGHT_PAREN))
    {
        do
        {
            if (params.size() >= 64) error(peek(), "Cannot have more than 64 parameters.");
            params.push_back(consume(IDENTIFIER, "Expect parameter name."));
        }
        while (match(COMMA));
    }

    consume(RIGHT_PAREN, "Expect ')' after parameters.");
    consume(LEFT_BRACE, "Expect '{' before " + kind + " body.");
    auto body = parseBlock();

    return std::make_shared<FunctionStatement>(name, params, body);
}

std::shared_ptr<Expression> Parser::finishCallDeclaration(std::shared_ptr<Expression> callee)
{
    std::vector<std::shared_ptr<Expression>> arguments;
    if (!check(RIGHT_PAREN))
    {
        do
        {
            if (arguments.size() >= 64) error(peek(), "Cannot have more than 64 arguments.");
            arguments.push_back(expression());
        }
        while (match(COMMA));
    }

    const Token paren = consume(RIGHT_PAREN, "Expect ')' after arguments.");
    return std::make_shared<Call>(callee, paren, arguments);
}

std::shared_ptr<Statement> Parser::printStatement()
{
    auto value = expression();
    consume(SEMICOLON, "Expect ';' after value.");
    return std::make_shared<PrintStatement>(value);
}

std::shared_ptr<Statement> Parser::ifStatement()
{
    consume(LEFT_PAREN, "Expect '(' after 'if'.");
    auto condition = expression();
    consume(RIGHT_PAREN, "Expect ')' after if condition.");
    auto thenBranch = statementDeclaration();
    auto elseBranch = match(ELSE) ? statementDeclaration() : nullptr;

    return std::make_shared<IfStatement>(condition, thenBranch, elseBranch);
}

std::shared_ptr<Statement> Parser::whileStatement()
{
    consume(LEFT_PAREN, "Expect '(' after 'while'.");
    auto condition = expression();
    consume(RIGHT_PAREN, "Expect ')' after condition.");
    auto body = statementDeclaration();

    return std::make_shared<WhileStatement>(condition, body);
}

std::shared_ptr<Statement> Parser::forStatement()
{
    consume(LEFT_PAREN, "Expect '(' after 'for'.");
    auto initializer = match(SEMICOLON) ? nullptr : (match(VAR) ? varDeclaration() : expressionStatement());
    auto condition = !check(SEMICOLON) ? expression() : nullptr;
    consume(SEMICOLON, "Expect ';' after loop condition.");
    auto increment = !check(RIGHT_PAREN) ? expression() : nullptr;
    consume(RIGHT_PAREN, "Expect ')' after for clauses.");
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
    consume(SEMICOLON, "Expect ';' after expression.");
    return std::make_shared<ExpressionStatement>(expr);
}

std::shared_ptr<Expression> Parser::logicalOr()
{
    auto expr = logicalAnd();

    while (match(OR))
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

    while (match(AND))
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

    while (!check(RIGHT_BRACE) && !isAtEnd())
    {
        statements.push_back(declaration());
    }

    consume(RIGHT_BRACE, "Expect '}' after block.");
    return statements;
}
