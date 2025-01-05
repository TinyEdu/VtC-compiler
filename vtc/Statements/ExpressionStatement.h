#ifndef EXPRESSIONSTATEMENT_H
#define EXPRESSIONSTATEMENT_H

#include "Statement.h"

class ExpressionStatement : public Statement
{
public:
    ExpressionStatement(Expression* expression) : expression(expression)
    {
    }

    ~ExpressionStatement() = default;

    std::any accept(StatementVisitor* visitor) override;

    bool equals(const Expression& other) const override;

    Expression* expression;
};

#endif
