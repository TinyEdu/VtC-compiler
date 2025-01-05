#ifndef WHILESTATEMENT_H
#define WHILESTATEMENT_H

#include "Statement.h"

class WhileStatement : public Statement
{
public:
    WhileStatement(Expression* condition, Statement* body)
        : condition(condition), body(body)
    {
    }

    ~WhileStatement() = default;

    std::any accept(StatementVisitor* visitor) override;

    bool equals(const Expression& other) const override;

    Expression* condition;
    Statement* body;
};

#endif
