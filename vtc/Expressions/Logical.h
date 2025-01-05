// Logical.h

#ifndef LOGICAL_H
#define LOGICAL_H

#include "Expression.h"

class Visitor;

class Logical : public Expression
{
public:
    Logical(Expression* left, Token op, Expression* right);
    std::any accept(Visitor* visitor) override;

    Expression* left;
    Token op;
    Expression* right;

    bool equals(const Expression& other) const override;

    friend std::ostream& operator<<(std::ostream& os, const Logical& expr);
    friend std::ostream& operator<<(std::ostream& os, const Logical* expr);
};

#endif  // LOGICAL_H
