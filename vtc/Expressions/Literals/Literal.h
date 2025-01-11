#ifndef LITERAL_H
#define LITERAL_H

#include "Expressions/Expression.h"
#include "Visitor/OperationsDispatcher.h"
#include "Token/Token.h"

// forward declarations
class LiteralInt;
class LiteralFloat;
class LiteralString;
class LiteralBool;
class LiteralDouble;

// class LiteralArray; // @TODO - implement arrays and chars
// class LiteralChar;

class Literal : public Expression, public std::enable_shared_from_this<Literal>
{
public:
    Literal() = default;
    ~Literal() override = default;

    virtual std::shared_ptr<Expression> accept(Visitor& visitor) = 0;

    bool equals(const Expression& other) const override;

    // [___] value;

    // declare double dispatch visiting functions
    // expr = left, this = right
    virtual std::shared_ptr<Expression> process(std::shared_ptr<Literal> expr, Token token) = 0;
    virtual std::shared_ptr<Expression> process(std::shared_ptr<LiteralInt> expr, Token token) = 0;
    virtual std::shared_ptr<Expression> process(std::shared_ptr<LiteralFloat> expr, Token token) = 0;
    virtual std::shared_ptr<Expression> process(std::shared_ptr<LiteralString> expr, Token token) = 0;
    virtual std::shared_ptr<Expression> process(std::shared_ptr<LiteralBool> expr, Token token) = 0;
    virtual std::shared_ptr<Expression> process(std::shared_ptr<LiteralDouble> expr, Token token) = 0;
    virtual std::shared_ptr<Expression> process(Token token) = 0;
    // @TODO: change to smart pointers
};

#endif  // LITERAL_H
