#ifndef FUNCTIONSTATEMENT_H
#define FUNCTIONSTATEMENT_H

#include "Statement.h"

class FunctionStatement : public Statement
{
public:
    FunctionStatement(Token name, std::vector<Token> params,
                      std::vector<Statement*> body)
        : name(name), params(params), body(body)
    {
    }

    ~FunctionStatement() = default;

    std::any accept(StatementVisitor* visitor) override;

    bool equals(const Expression& other) const override;

    Token name;
    std::vector<Token> params;
    std::vector<Statement*> body;
};

#endif
