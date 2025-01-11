#ifndef BLOCKSTATEMENT_H
#define BLOCKSTATEMENT_H

#include <memory>

#include "Statement.h"

class BlockStatement : public Statement, public std::enable_shared_from_this<BlockStatement>
{
public:
    BlockStatement(std::vector<std::shared_ptr<Statement>> statements);
    ~BlockStatement();

    std::any accept(StatementVisitor* visitor) override;

    bool equals(const Statement& other) const override;

    std::vector<std::shared_ptr<Statement>> statements;
};

#endif
