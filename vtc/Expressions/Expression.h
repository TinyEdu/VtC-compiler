// Expression.h

#ifndef EXPRESSION_H
#define EXPRESSION_H

#include <memory>

// forward declarations
class Assign;
class Binary;
class Grouping;
class Literal;
class Unary;
class Logical;
class Variable;

class Visitor;

class Expression
{
public:
    Expression() = default;
    virtual ~Expression() = default;

    virtual std::shared_ptr<Expression> accept(Visitor& visitor) = 0;

    // Virtual method for comparison
    virtual bool equals(const Expression& other) const = 0;

    // Overload operator==
    bool operator==(const Expression& other) const
    {
        return this->equals(other);
    }
};

#endif  // EXPRESSION_H
