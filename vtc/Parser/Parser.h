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

    std::vector<std::shared_ptr<Statement>> parse();

private:
    std::shared_ptr<Statement> declaration();
    std::shared_ptr<Expression> expression();
    std::shared_ptr<Expression> assignment();
    std::shared_ptr<Expression> logicalOr();
    std::shared_ptr<Expression> logicalAnd();
    std::shared_ptr<Expression> equality();
    std::shared_ptr<Expression> comparison();
    std::shared_ptr<Expression> term();
    std::shared_ptr<Expression> factor();
    std::shared_ptr<Expression> unary();
    std::shared_ptr<Expression> call();
    std::shared_ptr<Expression> primary();

    std::shared_ptr<Statement> varDeclaration();
    std::shared_ptr<Statement> statementDeclaration();
    std::shared_ptr<Statement> functionDeclaration(const std::string& kind);
    std::shared_ptr<Expression> finishCallDeclaration(std::shared_ptr<Expression> callee);


    std::shared_ptr<Statement> printStatement();
    std::shared_ptr<Statement> ifStatement();
    std::shared_ptr<Statement> whileStatement();
    std::shared_ptr<Statement> forStatement();
    std::shared_ptr<Statement> expressionStatement();

    std::vector<std::shared_ptr<Statement>> parseBlock();
};

#endif  // PARSER_H
