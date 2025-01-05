#ifndef RETURNSTATEMENT_H
#define RETURNSTATEMENT_H

#include "Statement.h"

class ReturnStatement : public Statement
{
public:
    ReturnStatement(Token keyword, Expression* value)
        : keyword(keyword), value(value)
    {
    }

    ~ReturnStatement() = default;

    std::any accept(StatementVisitor* visitor) override;

    bool equals(const Expression& other) const override;

    Token keyword;
    Expression* value;
};

#endif
