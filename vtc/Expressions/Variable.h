#ifndef VARIABLE_H
#define VARIABLE_H

#include "Expression.h"
#include "Token/Token.h"

class Visitor;

class Variable : public Expression, public std::enable_shared_from_this<Variable>
{
public:
    Variable(Token name);

    std::shared_ptr<Expression> accept(Visitor& visitor) override;

    Token name;

    bool equals(const Expression& other) const override;

    friend std::ostream& operator<<(std::ostream& os, const Variable* expr);
    friend std::ostream& operator<<(std::ostream& os, const Variable& expr);
};

#endif  // VARIABLE_H
