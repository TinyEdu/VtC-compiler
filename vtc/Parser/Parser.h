// Parser.h

#ifndef PARSER_H
#define PARSER_H


#include <vector>
#include <utility>

#include "Token/Token.h"
#include "Statements/Statement.h"
#include "ParseError.h"

// Forward declaration of Expression classes
class Expression;

class Binary;
class Grouping;
class Literal;
class Unary;

class Statement;


class Parser {
private:
    std::vector<Token> tokens;
    int currentIndex = 0;

public:
    explicit Parser(std::vector<Token> tokens);
    ~Parser();

private:
    Statement* declaration();
    Expression* assignment();
    Expression* expression();
    Expression* equality();
    Expression* comparison();
    Expression* term();
    Expression* factor();
    Expression* unary();
    Expression* call();
    Expression* primary();

    // logical
    Expression* logicalOr();
    Expression* logicalAnd();

    Token previous();
    bool match(std::vector<TokenType> types);
    Token advance();
    bool check(TokenType type);
    bool isAtEnd();
    Token peek();
    Token consume(TokenType type, const std::string& message);
    static ParseError error(Token token, const std::string& message);
    void synchronize();
    Statement* function(const std::string& kind);
    Statement* varDeclaration();
    Expression* finishCall(Expression* callee);


public:
    Expression* parseExpression();
    std::vector<Statement*> parse();
    Statement* expressionStatement();
    Statement* printStatement();
    Statement* ifStatement();
    Statement* whileStatement();
    Statement* forStatement();
    Statement* statement();
    std::vector<Statement*> block();

    friend class ParserTest;
};

#endif  // PARSER_H