// Variable.h

#ifndef VARIABLE_H
#define VARIABLE_H

#include "Expression.h"

class Visitor;

class Variable : public Expression
{
public:
    Variable(Token name);
    std::any accept(Visitor* visitor) override;

    Token name;

    bool equals(const Expression& other) const override;

    friend std::ostream& operator<<(std::ostream& os, const Variable* expr);
    friend std::ostream& operator<<(std::ostream& os, const Variable& expr);
};

#endif  // VARIABLE_H
