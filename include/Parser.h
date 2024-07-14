#include <vector>
#include "Token.h"

/*
expression     → equality ;
equality       → comparison ( ( "!=" | "==" ) comparison )* ;
comparison     → term ( ( ">" | ">=" | "<" | "<=" ) term )* ;
term           → factor ( ( "-" | "+" ) factor )* ;
factor         → unary ( ( "/" | "*" ) unary )* ;
unary          → ( "!" | "-" ) unary
               | primary ;
primary        → NUMBER | STRING | "true" | "false" | "nil"
               | "(" expression ")" ;
*/


class Parser
{
private:
    /* data */
public:
    Parser(std::vector<Token> tokens);
    ~Parser();

    std::vector<Token> tokens;
    int current = 0;
    
};

Parser::Parser(std::vector<Token> tokens)
    : tokens(tokens)
{
}

Parser::~Parser()
{
}
