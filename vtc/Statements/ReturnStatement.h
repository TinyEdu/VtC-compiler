#ifndef RETURNSTATEMENT_H
#define RETURNSTATEMENT_H

#include "Statement.h"

class ReturnStatement : public Statement
{
public:
    ReturnStatement(Token keyword, Expression* value);

    ~ReturnStatement();

    std::any accept(StatementVisitor* visitor) override;

    bool equals(const Statement& other) const override;

    Token keyword;
    Expression* value;
};

#endif
