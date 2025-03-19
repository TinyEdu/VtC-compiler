#ifndef ASSIGN_H
#define ASSIGN_H

#include "Expression.h"
#include "Token/Token.h"


class Visitor;

class Assign : public Expression, public std::enable_shared_from_this<Assign>
{
public:
    Assign(Token name, std::shared_ptr<Expression> value);

    std::shared_ptr<Expression> accept(Visitor& visitor) override;

    Token name;
    std::shared_ptr<Expression> value;

    bool equals(const Expression& other) const override;

    friend std::ostream& operator<<(std::ostream& os, const Assign& expr);
    friend std::ostream& operator<<(std::ostream& os, const Assign* expr);
};

#endif  // ASSIGN_H
