#include "Expressions/Literals/LiteralDouble.h"
#include "Expressions/Literals/LiteralBool.h"

#include "Visitor/OperationsDispatcher.h"
#include "Visitor/Visitor.h"

LiteralDouble::LiteralDouble(double value): value(value)
{

}

std::any LiteralDouble::accept(Visitor* visitor)
{
    return visitor->visit(this);
}

Expression* LiteralDouble::process(LiteralInt* expr, Token token)
{
    return OperationsDispatcher::dispatch(expr, this, token);
};

Expression* LiteralDouble::process(LiteralFloat* expr, Token token)
{
    return OperationsDispatcher::dispatch(expr, this, token);
};

Expression* LiteralDouble::process(LiteralString* expr, Token token)
{
    return OperationsDispatcher::dispatch(expr, this, token);
};

Expression* LiteralDouble::process(LiteralBool* expr, Token token)
{
    return OperationsDispatcher::dispatch(expr, this, token);
};

Expression* LiteralDouble::process(LiteralDouble* expr, Token token)
{
    return OperationsDispatcher::dispatch(expr, this, token);
};

Expression* LiteralDouble::process(Token token)
{
    return OperationsDispatcher::dispatch(this, token);
}

std::ostream& operator<<(std::ostream& os, const LiteralDouble* expr)
{
    os << expr->value;
    return os;
}

std::ostream& operator<<(std::ostream& os, const LiteralDouble& expr)
{
    os << expr.value;
    return os;
}
