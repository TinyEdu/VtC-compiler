#include <utility>

#include "Expressions/Literals/LiteralString.h"
#include "Expressions/Literals/LiteralBool.h"

#include "Visitor/OperationsDispatcher.h"
#include "Visitor/Visitor.h"

LiteralString::LiteralString(std::string value): value(std::move(value))
{

}

std::any LiteralString::accept(Visitor* visitor)
{
    return visitor->visit(this);
}

Expression* LiteralString::process(Literal* expr, Token token)
{
    return expr->process(this, token);
}

Expression* LiteralString::process(LiteralInt* expr, Token token)
{
    return OperationsDispatcher::dispatch(expr, this, token);
};

Expression* LiteralString::process(LiteralFloat* expr, Token token)
{
    return OperationsDispatcher::dispatch(expr, this, token);
};

Expression* LiteralString::process(LiteralString* expr, Token token)
{
    return OperationsDispatcher::dispatch(expr, this, token);
};

Expression* LiteralString::process(LiteralBool* expr, Token token)
{
    return OperationsDispatcher::dispatch(expr, this, token);
};

Expression* LiteralString::process(LiteralDouble* expr, Token token)
{
    return OperationsDispatcher::dispatch(expr, this, token);
};

Expression* LiteralString::process(Token token)
{
    return OperationsDispatcher::dispatch(this, token);
}

std::ostream& operator<<(std::ostream& os, const LiteralString* expr)
{
    os << expr->value;
    return os;
}

std::ostream& operator<<(std::ostream& os, const LiteralString& expr)
{
    os << expr.value;
    return os;
}
