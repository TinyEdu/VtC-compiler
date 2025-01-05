#ifndef PRINTSTATEMENT_H
#define PRINTSTATEMENT_H

#include "Statement.h"

class PrintStatement : public Statement
{
public:
    PrintStatement(Expression* expression) : expression(expression)
    {
    }

    ~PrintStatement() = default;

    std::any accept(StatementVisitor* visitor) override;

    bool equals(const Expression& other) const override;

    Expression* expression;
};

#endif
