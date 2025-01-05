// Binary.h

#ifndef BINARY_H
#define BINARY_H

#include "Expression.h"

class Visitor;

class Binary : public Expression
{
public:
    Binary(Expression* left, Token op, Expression* right);
    std::any accept(Visitor* visitor) override;

    Expression* left;
    Token op;
    Expression* right;

    bool equals(const Expression& other) const override;

    friend std::ostream& operator<<(std::ostream& os, const Binary* expr);
    friend std::ostream& operator<<(std::ostream& os, const Binary& expr);
};

#endif  // BINARY_H
