#ifndef VARSTATEMENT_H
#define VARSTATEMENT_H

#include "Statement.h"

class VarStatement : public Statement
{
public:
    VarStatement(Token name, Expression* initializer);

    ~VarStatement();

    std::any accept(StatementVisitor* visitor) override;

    bool equals(const Statement& other) const override;

    Token name;
    Expression* initializer;
};

#endif
