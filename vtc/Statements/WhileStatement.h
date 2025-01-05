#ifndef WHILESTATEMENT_H
#define WHILESTATEMENT_H

#include "Statement.h"

class WhileStatement : public Statement
{
public:
    WhileStatement(Expression* condition, Statement* body);

    ~WhileStatement();

    std::any accept(StatementVisitor* visitor) override;

    bool equals(const Statement& other) const override;

    Expression* condition;
    Statement* body;
};

#endif
