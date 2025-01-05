// LiteralDouble.h

#ifndef LiteralDouble_H
#define LiteralDouble_H

#include "Expressions/Literals/Literal.h"

class Expression;
class LiteralInt;
class LiteralFloat;
class LiteralString;
class LiteralBool;

class LiteralDouble : public Literal
{
public:
    explicit LiteralDouble(double value);

    double value;

    std::any accept(Visitor* visitor) override;

    Expression* process(Literal* expr, Token token) override;

    Expression* process(LiteralInt* expr, Token token) override;
    Expression* process(LiteralFloat* expr, Token token) override;
    Expression* process(LiteralString* expr, Token token) override;
    Expression* process(LiteralBool* expr, Token token) override;
    Expression* process(LiteralDouble* expr, Token token) override;
    Expression* process(Token token) override;

    friend std::ostream& operator<<(std::ostream& os, const LiteralBool* expr);
    friend std::ostream& operator<<(std::ostream& os, const LiteralBool& expr);
};
#endif  // LiteralDouble_H
