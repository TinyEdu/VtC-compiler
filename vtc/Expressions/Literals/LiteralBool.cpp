#include "Expressions/Literals/LiteralBool.h"
#include "Expressions/Literals/LiteralDouble.h"

#include "Visitor/OperationsDispatcher.h"
#include "Visitor/Visitor.h"

LiteralBool::LiteralBool(bool value): value(value)
{
}

std::any LiteralBool::accept(Visitor* visitor)
{
    return visitor->visit(this);
}

Expression* LiteralBool::process(Literal* expr, Token token)
{
    return expr->process(this, token);
}

Expression* LiteralBool::process(LiteralInt* expr, Token token)
{
    return
        OperationsDispatcher::dispatch(expr, this, token);
};

Expression* LiteralBool::process(LiteralFloat* expr, Token token)
{
    return OperationsDispatcher::dispatch(expr, this, token);
};

Expression* LiteralBool::process(LiteralString* expr, Token token)
{
    return OperationsDispatcher::dispatch(expr, this, token);
};

Expression* LiteralBool::process(LiteralBool* expr, Token token)
{
    return OperationsDispatcher::dispatch(expr, this, token);
};

Expression* LiteralBool::process(LiteralDouble* expr, Token token)
{
    return OperationsDispatcher::dispatch(expr, this, token);
};

Expression* LiteralBool::process(Token token)
{
    return OperationsDispatcher::dispatch(this, token);
}

std::ostream& operator<<(std::ostream& os, const LiteralBool* expr)
{
    os << expr->value;
    return os;
}

std::ostream& operator<<(std::ostream& os, const LiteralBool& expr)
{
    os << expr.value;
    return os;
}
