// Unary.h

#ifndef UNARY_H
#define UNARY_H

#include "Expression.h"

class Visitor;

class Unary : public Expression
{
public:
    Unary(Token op, Expression* right);
    std::any accept(Visitor* visitor) override;

    Token op;
    Expression* right;

    bool equals(const Expression& other) const override;

    friend std::ostream& operator<<(std::ostream& os, const Unary* expr);
    friend std::ostream& operator<<(std::ostream& os, const Unary& expr);
};

#endif  // UNARY_H
