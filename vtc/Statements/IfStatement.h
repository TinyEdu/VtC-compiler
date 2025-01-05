#ifndef IFSTATEMENT_H
#define IFSTATEMENT_H

#include "Statement.h"

class IfStatement : public Statement
{
public:
    IfStatement(Expression* condition, Statement* thenBranch,
                Statement* elseBranch)
        : condition(condition), thenBranch(thenBranch), elseBranch(elseBranch)
    {
    }

    ~IfStatement() = default;

    std::any accept(StatementVisitor* visitor) override;

    bool equals(const Expression& other) const override;

    Expression* condition;
    Statement* thenBranch;
    Statement* elseBranch;
};

#endif
