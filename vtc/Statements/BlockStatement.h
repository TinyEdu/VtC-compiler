#ifndef BLOCKSTATEMENT_H
#define BLOCKSTATEMENT_H

#include "Statement.h"

class BlockStatement : public Statement
{
public:
    BlockStatement(std::vector<Statement*> statements) : statements(statements)
    {
    }

    ~BlockStatement() = default;

    std::any accept(StatementVisitor* visitor) override;

    bool equals(const Expression& other) const override;

    std::vector<Statement*> statements;
};

#endif
