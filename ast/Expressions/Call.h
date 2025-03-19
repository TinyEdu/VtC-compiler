#ifndef CALL_H
#define CALL_H

#include "Expression.h"
#include "Token/Token.h"
#include <vector>

class Visitor;

class Call : public Expression, public std::enable_shared_from_this<Call>
{
public:
    Call(std::shared_ptr<Expression> callee, Token paren, std::vector<std::shared_ptr<Expression>> arguments);

    std::shared_ptr<Expression> accept(Visitor& visitor) override;

    std::shared_ptr<Expression> callee;
    Token paren;
    std::vector<std::shared_ptr<Expression>> arguments;

    bool equals(const Expression& other) const override;

    friend std::ostream& operator<<(std::ostream& os, const Call& expr);
    friend std::ostream& operator<<(std::ostream& os, const Call* expr);
};

#endif  // CALL_H
