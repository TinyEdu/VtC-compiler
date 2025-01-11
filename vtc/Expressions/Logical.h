#ifndef LOGICAL_H
#define LOGICAL_H

#include "Expression.h"
#include "Token/Token.h"

class Visitor;

class Logical : public Expression, public std::enable_shared_from_this<Logical>
{
public:
    Logical(std::shared_ptr<Expression> left, Token op, std::shared_ptr<Expression> right);

    std::shared_ptr<Expression> accept(Visitor& visitor) override;

    std::shared_ptr<Expression> left;
    Token op;
    std::shared_ptr<Expression> right;

    bool equals(const Expression& other) const override;

    friend std::ostream& operator<<(std::ostream& os, const Logical& expr);
    friend std::ostream& operator<<(std::ostream& os, const Logical* expr);
};

#endif  // LOGICAL_H
