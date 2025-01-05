#ifndef BLOCKSTATEMENT_H
#define BLOCKSTATEMENT_H

#include "Statement.h"

class BlockStatement : public Statement
{
public:
    BlockStatement(std::vector<Statement*> statements);
    ~BlockStatement();

    std::any accept(StatementVisitor* visitor) override;

    bool equals(const Statement& other) const override;

    std::vector<Statement*> statements;
};

#endif
