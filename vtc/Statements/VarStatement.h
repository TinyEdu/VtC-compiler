#ifndef VARSTATEMENT_H
#define VARSTATEMENT_H

#include "Statement.h"

class VarStatement : public Statement
{
public:
    VarStatement(Token name, Expression* initializer)
        : name(name), initializer(initializer)
    {
    }

    ~VarStatement() = default;

    std::any accept(StatementVisitor* visitor) override;

    bool equals(const Expression& other) const override;

    Token name;
    Expression* initializer;
};

#endif
