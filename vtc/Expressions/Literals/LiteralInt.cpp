#include "Expressions/Literals/LiteralInt.h"
#include "Expressions/Literals/LiteralBool.h"

#include "Visitor/OperationsDispatcher.h"
#include "Visitor/Visitor.h"

LiteralInt::LiteralInt(int value): value(value)
{

}

std::any LiteralInt::accept(Visitor* visitor)
{
    return visitor->visit(this);
}

Expression* LiteralInt::process(Literal* expr, Token token)
{
    return expr->process(this, token);
}

Expression* LiteralInt::process(LiteralInt* expr, Token token)
{
    return OperationsDispatcher::dispatch(expr, this, token);
};

Expression* LiteralInt::process(LiteralFloat* expr, Token token)
{
    return OperationsDispatcher::dispatch(expr, this, token);
};

Expression* LiteralInt::process(LiteralString* expr, Token token)
{
    return OperationsDispatcher::dispatch(expr, this, token);
};

Expression* LiteralInt::process(LiteralBool* expr, Token token)
{
    return OperationsDispatcher::dispatch(expr, this, token);
};

Expression* LiteralInt::process(LiteralDouble* expr, Token token)
{
    return OperationsDispatcher::dispatch(expr, this, token);
};

Expression* LiteralInt::process(Token token)
{
    return OperationsDispatcher::dispatch(this, token);
}

std::ostream& operator<<(std::ostream& os, const LiteralInt* expr)
{
    os << expr->value;
    return os;
}

std::ostream& operator<<(std::ostream& os, const LiteralInt& expr)
{
    os << expr.value;
    return os;
}
