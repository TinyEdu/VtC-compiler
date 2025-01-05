#ifndef EXPRESSIONSTATEMENT_H
#define EXPRESSIONSTATEMENT_H

#include "Statement.h"

class ExpressionStatement : public Statement
{
public:
    ExpressionStatement(Expression* expression);

    ~ExpressionStatement();

    std::any accept(StatementVisitor* visitor) override;

    bool equals(const Statement& other) const override;

    Expression* expression;
};

#endif
