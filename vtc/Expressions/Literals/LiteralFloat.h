// LiteralFloat.h

#ifndef LiteralFloat_H
#define LiteralFloat_H

#include "Expressions/Literals/Literal.h"

class Expression;
class LiteralInt;
class LiteralString;
class LiteralBool;
class LiteralDouble;

class LiteralFloat : public Literal
{
public:
    explicit LiteralFloat(float value);

    float value;

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
#endif  // LiteralFloat_H
