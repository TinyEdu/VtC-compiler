// LiteralInt.h

#ifndef LiteralInt_H
#define LiteralInt_H

#include "Expressions/Literals/Literal.h"

class Expression;
class LiteralFloat;
class LiteralString;
class LiteralBool;
class LiteralDouble;

class LiteralInt : public Literal
{
public:
    explicit LiteralInt(int value);

    int value;

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
#endif  // LiteralInt_H
