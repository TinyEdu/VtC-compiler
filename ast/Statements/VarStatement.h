#ifndef VARSTATEMENT_H
#define VARSTATEMENT_H

#include <memory>

#include "Statement.h"

class VarStatement : public Statement, public std::enable_shared_from_this<VarStatement>
{
public:
    VarStatement(Token name, std::shared_ptr<Expression> initializer);

    ~VarStatement();

    std::any accept(StatementVisitor* visitor) override;

    bool equals(const Statement& other) const override;

    Token name;
    std::shared_ptr<Expression> initializer;
};

#endif
