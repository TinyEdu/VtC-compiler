#include "Expressions/Literals/LiteralFloat.h"
#include "Expressions/Literals/LiteralBool.h"

#include "Visitor/OperationsDispatcher.h"
#include "Visitor/Visitor.h"


LiteralFloat::LiteralFloat(float value): value(value)
{
}

std::any LiteralFloat::accept(Visitor* visitor)
{
    return visitor->visit(this);
}

Expression* LiteralFloat::process(Literal* expr, Token token)
{
    return expr->process(this, token);
}

Expression* LiteralFloat::process(LiteralInt* expr, Token token)
{
    return OperationsDispatcher::dispatch(expr, this, token);
};

Expression* LiteralFloat::process(LiteralFloat* expr, Token token)
{
    return OperationsDispatcher::dispatch(expr, this, token);
};

Expression* LiteralFloat::process(LiteralString* expr, Token token)
{
    return OperationsDispatcher::dispatch(expr, this, token);
};

Expression* LiteralFloat::process(LiteralBool* expr, Token token)
{
    return OperationsDispatcher::dispatch(expr, this, token);
};

Expression* LiteralFloat::process(LiteralDouble* expr, Token token)
{
    return OperationsDispatcher::dispatch(expr, this, token);
};

Expression* LiteralFloat::process(Token token)
{
    return OperationsDispatcher::dispatch(this, token);
}

std::ostream& operator<<(std::ostream& os, const LiteralFloat* expr)
{
    os << expr->value;
    return os;
}

std::ostream& operator<<(std::ostream& os, const LiteralFloat& expr)
{
    os << expr.value;
    return os;
}
