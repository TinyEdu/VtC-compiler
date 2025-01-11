#ifndef WHILESTATEMENT_H
#define WHILESTATEMENT_H

#include <memory>

#include "Statement.h"

class WhileStatement : public Statement, public std::enable_shared_from_this<WhileStatement>
{
public:
    WhileStatement(std::shared_ptr<Expression> condition, std::shared_ptr<Statement> body);

    ~WhileStatement();

    std::any accept(StatementVisitor* visitor) override;

    bool equals(const Statement& other) const override;

    std::shared_ptr<Expression> condition;
    std::shared_ptr<Statement> body;
};

#endif
