#ifndef LiteralDouble_H
#define LiteralDouble_H

#include "Literal.h"

class Expression;
class LiteralInt;
class LiteralFloat;
class LiteralString;
class LiteralBool;
class LiteralDouble;

class LiteralDouble : public Literal
{
public:
    explicit LiteralDouble(double value);

    double value;

    std::shared_ptr<Expression> accept(Visitor& visitor) override;

    std::shared_ptr<Expression> process(std::shared_ptr<Literal> expr, Token token) override;
    std::shared_ptr<Expression> process(std::shared_ptr<LiteralInt> expr, Token token) override;
    std::shared_ptr<Expression> process(std::shared_ptr<LiteralFloat> expr, Token token) override;
    std::shared_ptr<Expression> process(std::shared_ptr<LiteralString> expr, Token token) override;
    std::shared_ptr<Expression> process(std::shared_ptr<LiteralBool> expr, Token token) override;
    std::shared_ptr<Expression> process(std::shared_ptr<LiteralDouble> expr, Token token) override;

    std::shared_ptr<Expression> process(Token token) override;

    friend std::ostream& operator<<(std::ostream& os, const LiteralDouble* expr);
    friend std::ostream& operator<<(std::ostream& os, const LiteralDouble& expr);
};

#endif  // LiteralDouble_H
