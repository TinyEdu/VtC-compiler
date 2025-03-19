// Unary.h

#ifndef UNARY_H
#define UNARY_H

#include "Expression.h"
#include "Token/Token.h"

class Visitor;

class Unary : public Expression, public std::enable_shared_from_this<Unary>
{
public:
    Unary(Token op, std::shared_ptr<Expression> right);

    std::shared_ptr<Expression> accept(Visitor& visitor) override;

    Token op;
    std::shared_ptr<Expression> right;

    bool equals(const Expression& other) const override;

    friend std::ostream& operator<<(std::ostream& os, const Unary* expr);
    friend std::ostream& operator<<(std::ostream& os, const Unary& expr);
};

#endif  // UNARY_H
