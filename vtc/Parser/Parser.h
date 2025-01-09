// Parser.h

#ifndef PARSER_H
#define PARSER_H

#include <memory>
#include <vector>

#include "Token/Token.h"
#include "Statements/Statement.h"
#include "ParserBase.h"

// Forward declarations
class Expression;
class Statement;


class Parser : protected ParserBase
{
public:
    explicit Parser(std::vector<Token> tokens);
    ~Parser();

    std::vector<std::unique_ptr<Statement>> parse();

private:
    Statement* declaration();
    Expression* expression();
    Expression* assignment();
    Expression* logicalOr();
    Expression* logicalAnd();
    Expression* equality();
    Expression* comparison();
    Expression* term();
    Expression* factor();
    Expression* unary();
    Expression* call();
    Expression* primary();

    Statement* varDeclaration();
    Statement* statementDeclaration();
    Statement* functionDeclaration(const std::string& kind);
    Expression* finishCallDeclaration(Expression& callee);


    Statement* printStatement();
    Statement* ifStatement();
    Statement* whileStatement();
    Statement* forStatement();
    Statement* expressionStatement();

    std::vector<Statement*> parseBlock();
};

#endif  // PARSER_H
