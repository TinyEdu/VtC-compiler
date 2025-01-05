#ifndef IFSTATEMENT_H
#define IFSTATEMENT_H

#include "Statement.h"

class IfStatement : public Statement
{
public:
    IfStatement(Expression* condition, Statement* thenBranch,
                Statement* elseBranch);

    ~IfStatement();

    std::any accept(StatementVisitor* visitor) override;

    bool equals(const Statement& other) const override;

    Expression* condition;
    Statement* thenBranch;
    Statement* elseBranch;
};

#endif
