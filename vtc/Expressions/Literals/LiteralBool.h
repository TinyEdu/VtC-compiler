// LiteralBool.h

#ifndef LiteralBool_H
#define LiteralBool_H

#include "Expressions/Literals/Literal.h"

class Expression;
class LiteralInt;
class LiteralFloat;
class LiteralString;
class LiteralDouble;

class LiteralBool : public Literal
{
public:
    explicit LiteralBool(bool value);;

    bool value;

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
#endif  // LiteralBool_H
