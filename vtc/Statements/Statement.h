#ifndef STATEMENT_H
#define STATEMENT_H

#include <any>
#include <vector>
#include "Token/Token.h"

class Expression;
class StatementVisitor;

class Statement
{
public:
    Statement() = default;
    virtual ~Statement() = default;
    virtual std::any accept(StatementVisitor* visitor) = 0;

    // Virtual method for comparison
    virtual bool equals(const Expression& other) const = 0;

    // Overload operator==
    bool operator==(const Expression& other) const
    {
        return this->equals(other);
    }
};

#endif  // STATEMENT_H
