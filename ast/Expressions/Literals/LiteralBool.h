#ifndef LiteralBool_H
#define LiteralBool_H

#include "Literal.h"

class Expression;
class LiteralInt;
class LiteralFloat;
class LiteralString;
class LiteralDouble;

class LiteralBool : public Literal
{
public:
    explicit LiteralBool(bool value);

    bool value;

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
#endif  // LiteralBool_H
