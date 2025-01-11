#ifndef LiteralString_H
#define LiteralString_H

#include "Literal.h"

class Expression;
class LiteralInt;
class LiteralFloat;
class LiteralBool;
class LiteralDouble;

class LiteralString : public Literal
{
public:
    explicit LiteralString(std::string value);

    std::string value;

    std::shared_ptr<Expression> accept(Visitor& visitor) override;

    std::shared_ptr<Expression> process(std::shared_ptr<Literal> expr, Token token) override;
    std::shared_ptr<Expression> process(std::shared_ptr<LiteralInt> expr, Token token) override;
    std::shared_ptr<Expression> process(std::shared_ptr<LiteralFloat> expr, Token token) override;
    std::shared_ptr<Expression> process(std::shared_ptr<LiteralString> expr, Token token) override;
    std::shared_ptr<Expression> process(std::shared_ptr<LiteralBool> expr, Token token) override;
    std::shared_ptr<Expression> process(std::shared_ptr<LiteralDouble> expr, Token token) override;

    std::shared_ptr<Expression> process(Token token) override;

    friend std::ostream& operator<<(std::ostream& os, const LiteralBool* expr);
    friend std::ostream& operator<<(std::ostream& os, const LiteralBool& expr);
};
#endif  // LiteralString_H
