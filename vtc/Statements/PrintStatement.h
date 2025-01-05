#ifndef PRINTSTATEMENT_H
#define PRINTSTATEMENT_H

#include "Statement.h"

class PrintStatement : public Statement
{
public:
    explicit PrintStatement(Expression* expression);

    ~PrintStatement();

    std::any accept(StatementVisitor* visitor) override;

    bool equals(const Statement& other) const override;

    Expression* expression;
};

#endif
