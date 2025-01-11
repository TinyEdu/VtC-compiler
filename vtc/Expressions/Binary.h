// Binary.h

#ifndef BINARY_H
#define BINARY_H

#include "Expression.h"
#include "Token/Token.h"

class Visitor;

class Binary : public Expression, public std::enable_shared_from_this<Binary>
{
public:
    Binary(std::shared_ptr<Expression> left, Token op, std::shared_ptr<Expression> right);

    std::shared_ptr<Expression> accept(Visitor& visitor) override;

    std::shared_ptr<Expression> left;
    Token op;
    std::shared_ptr<Expression> right;

    bool equals(const Expression& other) const override;

    friend std::ostream& operator<<(std::ostream& os, const Binary* expr);
    friend std::ostream& operator<<(std::ostream& os, const Binary& expr);
};

#endif  // BINARY_H
