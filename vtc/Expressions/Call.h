// Call.h

#ifndef CALL_H
#define CALL_H

#include "Expression.h"
#include <vector>

class Visitor;

class Call : public Expression
{
public:
    Call(Expression* callee, Token paren, std::vector<Expression*> arguments);
    std::any accept(Visitor* visitor) override;

    Expression* callee;
    Token paren;
    std::vector<Expression*> arguments;

    bool equals(const Expression& other) const override;

    friend std::ostream& operator<<(std::ostream& os, const Call& expr);
    friend std::ostream& operator<<(std::ostream& os, const Call* expr);
};

#endif  // CALL_H
