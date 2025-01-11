#ifndef IFSTATEMENT_H
#define IFSTATEMENT_H

#include <memory>

#include "Statement.h"

class IfStatement : public Statement, public std::enable_shared_from_this<IfStatement>
{
public:
    IfStatement(std::shared_ptr<Expression> condition, std::shared_ptr<Statement> thenBranch,
                std::shared_ptr<Statement> elseBranch);

    ~IfStatement();

    std::any accept(StatementVisitor* visitor) override;

    bool equals(const Statement& other) const override;

    std::shared_ptr<Expression> condition;
    std::shared_ptr<Statement> thenBranch;
    std::shared_ptr<Statement> elseBranch;
};

#endif
