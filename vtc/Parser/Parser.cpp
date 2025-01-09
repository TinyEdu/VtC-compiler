// Parser.cpp
#include "Parser.h"

#include <algorithm>
#include <utility>

#include "Expressions/ExpressionsWorld.h"
#include "Statements/StatementsWorld.h"
#include "LogManager/LogManager.h"

using enum TokenType;


Parser::Parser(std::vector<Token> tokens) : ParserBase(std::move(tokens))
{
}

Parser::~Parser() = default;

std::vector<std::unique_ptr<Statement>> Parser::parse()
{
    std::vector<std::unique_ptr<Statement>> statements;

    while (!isAtEnd())
    {
        auto a = declaration();
        statements.push_back(std::unique_ptr<Statement>(a));
    }

    return statements;
}

// ----------------------------------------------------------------------------------------------

Statement* Parser::declaration()
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

Expression* Parser::expression()
{
    return assignment();
}

Expression* Parser::assignment()
{
    Expression* expr = logicalOr();

    if (match(EQUAL))
    {
        const Token equals = previous();
        Expression* value = assignment();

        if (const auto varExpr = dynamic_cast<Variable*>(expr))
        {
            const Token name = varExpr->name;
            return new Assign(name, value);
        }

        error(equals, "Invalid assignment target.");
    }

    return expr;
}

Expression* Parser::equality()
{
    Expression* expr = comparison();

    while (match({BANG_EQUAL, EQUAL_EQUAL}))
    {
        const Token op = previous();
        Expression* right = comparison();

        expr = new Binary(expr, op, right);
    }

    return expr;
}

Expression* Parser::comparison()
{
    Expression* expr = term();

    while (match({GREATER, GREATER_EQUAL, LESS, LESS_EQUAL}))
    {
        const Token op = previous();
        Expression* right = term();

        expr = new Binary(expr, op, right);
    }

    return expr;
}

Expression* Parser::term()
{
    Expression* expr = factor();

    while (match({MINUS, PLUS}))
    {
        Token op = previous();
        Expression* right = factor();

        expr = new Binary(expr, op, right);
    }

    return expr;
}

Expression* Parser::factor()
{
    Expression* expr = unary();

    while (match({SLASH, STAR}))
    {
        Token op = previous();
        Expression* right = unary();

        expr = new Binary(expr, op, right);
    }

    return expr;
}

Expression* Parser::unary()
{
    if (match({BANG, MINUS}))
    {
        Token op = previous();
        Expression* right = unary();

        return new Unary(op, right);
    }
    return call();
}

Expression* Parser::call()
{
    Expression* expr = primary();

    while (true)
    {
        if (match(LEFT_PAREN))
        {
            expr = finishCallDeclaration(*expr);
        }
        else
        {
            break;
        }
    }

    return expr;
}

Expression* Parser::primary()
{
    if (match(FALSE))
        return new LiteralBool(false);
    if (match(TRUE))
        return new LiteralBool(true);
    if (match(NIL))
        return new LiteralInt(0); // @TODO - how to handle NULL values?
    if (match(NUMBER))
    {
        // check if the given value is an integer or a double
        if (previous().literal.find('.') != std::string::npos)
        {
            // is a double
            return new LiteralDouble(std::stod(previous().literal));
        }
        else
        {
            // is an integer
            return new LiteralInt(std::stoi(previous().literal));
        }
    }

    if (match(STRING))
    {
        return new LiteralString(previous().literal);
    }
    if (match(LEFT_PAREN))
    {
        Expression* expr = expression();
        consume(RIGHT_PAREN, "Expect ')' after expression.");
        return new Grouping(expr);
    }
    if (match(IDENTIFIER))
    {
        return new Variable(previous());
    }

    throw ParseError("Expect expression.");
}

// ----------------------------------------------------------------------------------------------

Statement* Parser::varDeclaration()
{
    const Token name = consume(IDENTIFIER, "Expect variable name.");

    Expression* initializer = nullptr;
    if (match(EQUAL))
    {
        initializer = expression();
    }

    consume(SEMICOLON, "Expect ';' after variable declaration.");
    return new VarStatement(name, initializer);
}

Statement* Parser::statementDeclaration()
{
    if (match(FOR))
    {
        return forStatement();
    }
    if (match(IF))
    {
        return ifStatement();
    }
    if (match(WHILE))
    {
        return whileStatement();
    }
    if (match(PRINT))
    {
        return printStatement();
    }
    if (match(LEFT_BRACE))
    {
        return new BlockStatement(parseBlock());
    }
    if (match(RETURN))
    {
        const Token keyword = previous();
        Expression* value = nullptr;
        if (!check(SEMICOLON))
        {
            value = expression();
        }
        consume(SEMICOLON, "Expect ';' after return value.");

        return new ReturnStatement(keyword, value);
    }

    return expressionStatement();
}

Statement* Parser::functionDeclaration(const std::string& kind)
{
    const Token name = consume(IDENTIFIER, "Expect " + kind + " name.");

    consume(LEFT_PAREN, "Expect '(' after " + kind + " name.");
    std::vector<Token> params;

    if (!check(RIGHT_PAREN))
    {
        do
        {
            if (params.size() >= 64)
            {
                error(peek(), "Function definitions cannot have more than 64 parameters.");
            }
            params.push_back(consume(IDENTIFIER, "Expect parameter name."));
        }
        while (match(COMMA));
    }

    consume(RIGHT_PAREN, "Expect ')' after parameters.");

    consume(LEFT_BRACE, "Expect '{' before " + kind + " body.");
    const std::vector<Statement*> body = parseBlock();
    return new FunctionStatement(name, params, body);
}

Expression* Parser::finishCallDeclaration(Expression& callee)
{
    std::vector<Expression*> arguments;
    if (!check(RIGHT_PAREN))
    {
        do
        {
            if (arguments.size() >= 64)
            {
                error(peek(), "Function definitions cannot have more than 64 arguments.");
            }
            arguments.push_back(expression());
        }
        while (match({COMMA}));
    }

    const Token paren = consume(RIGHT_PAREN, "Expect ')' after arguments.");

    return new Call(&callee, paren, arguments);
}

// ----------------------------------------------------------------------------------------------

Statement* Parser::printStatement()
{
    Expression* value = expression();
    consume(SEMICOLON, "Expect ';' after value.");
    return new PrintStatement(value);
}

Statement* Parser::ifStatement()
{
    consume(LEFT_PAREN, "Expect '(' after 'if'.");
    Expression* condition = expression();
    consume(RIGHT_PAREN, "Expect ')' after if condition.");

    Statement* thenBranch = statementDeclaration();
    Statement* elseBranch = nullptr;
    if (match(ELSE))
    {
        elseBranch = statementDeclaration();
    }

    return new IfStatement(condition, thenBranch, elseBranch);
}

Statement* Parser::whileStatement()
{
    consume(LEFT_PAREN, "Expect '(' after 'while'.");
    Expression* condition = expression();
    consume(RIGHT_PAREN, "Expect ')' after condition.");
    Statement* body = statementDeclaration();

    return new WhileStatement(condition, body);
}

Statement* Parser::forStatement()
{
    consume(LEFT_PAREN, "Expect '(' after 'for'.");

    Statement* initializer = nullptr;
    if (match(SEMICOLON))
    {
        initializer = nullptr;
    }
    else if (match(VAR))
    {
        initializer = varDeclaration();
    }
    else
    {
        initializer = expressionStatement();
    }

    Expression* condition = nullptr;
    if (!check(SEMICOLON))
    {
        condition = expression();
    }
    consume(SEMICOLON, "Expect ';' after loop condition.");

    Expression* increment = nullptr;
    if (!check(RIGHT_PAREN))
    {
        increment = expression();
    }
    consume(RIGHT_PAREN, "Expect ')' after for clauses.");

    Statement* body = statementDeclaration();

    // Desugar increment: if increment is non-null, append it to the end of the loop body
    if (increment != nullptr)
    {
        body = new BlockStatement({body, new ExpressionStatement(increment)});
    }

    // Desugar condition: if condition is null, set it to `true`
    if (condition == nullptr)
    {
        condition = new LiteralBool(true);
    }

    // Create the loop using the while statement with the desugared condition
    body = new WhileStatement(condition, body);

    // Desugar initializer: if initializer is non-null, wrap everything in a new block with the initializer
    if (initializer != nullptr)
    {
        body = new BlockStatement({initializer, body});
    }

    return body;
}


Statement* Parser::expressionStatement()
{
    Expression* expr = expression();
    consume(SEMICOLON, "Expect ';' after expression.");

    return new ExpressionStatement(expr);
}

Expression* Parser::logicalOr()
{
    Expression* expr = logicalAnd();

    while (match(OR))
    {
        const Token op = previous();
        Expression* right = logicalAnd();
        expr = new Logical(expr, op, right);
    }

    // if 'or' was not found it returns equality()
    return expr;
}


Expression* Parser::logicalAnd()
{
    Expression* expr = equality();

    while (match(AND))
    {
        const Token op = previous();
        Expression* right = equality();
        expr = new Logical(expr, op, right);
    }

    // if 'and' was not found it returns equality()
    return expr;
}

std::vector<Statement*> Parser::parseBlock()
{
    std::vector<Statement*> statements;

    while (!check(RIGHT_BRACE) && !isAtEnd())
    {
        statements.push_back(declaration());
    }

    consume(RIGHT_BRACE, "Expect '}' after block.");
    return statements;
}
