#include "LiteralDouble.h"

#include "Visitor/OperationsDispatcher.h"
#include "Visitor/Visitor.h"

LiteralDouble::LiteralDouble(double value) : value(value)
{
}

std::shared_ptr<Expression> LiteralDouble::accept(Visitor& visitor)
{
    return visitor.visit(std::dynamic_pointer_cast<LiteralDouble>(shared_from_this()));
}

std::shared_ptr<Expression> LiteralDouble::process(std::shared_ptr<Literal> expr, Token token)
{
    return expr->process(std::dynamic_pointer_cast<LiteralDouble>(shared_from_this()), token);
}

std::shared_ptr<Expression> LiteralDouble::process(std::shared_ptr<LiteralInt> expr, Token token)
{
    return OperationsDispatcher::dispatch(expr, std::dynamic_pointer_cast<LiteralDouble>(shared_from_this()), token);
}

std::shared_ptr<Expression> LiteralDouble::process(std::shared_ptr<LiteralFloat> expr, Token token)
{
    return OperationsDispatcher::dispatch(expr, std::dynamic_pointer_cast<LiteralDouble>(shared_from_this()), token);
}

std::shared_ptr<Expression> LiteralDouble::process(std::shared_ptr<LiteralString> expr, Token token)
{
    return OperationsDispatcher::dispatch(expr, std::dynamic_pointer_cast<LiteralDouble>(shared_from_this()), token);
}

std::shared_ptr<Expression> LiteralDouble::process(std::shared_ptr<LiteralBool> expr, Token token)
{
    return OperationsDispatcher::dispatch(expr, std::dynamic_pointer_cast<LiteralDouble>(shared_from_this()), token);
}

std::shared_ptr<Expression> LiteralDouble::process(std::shared_ptr<LiteralDouble> expr, Token token)
{
    return OperationsDispatcher::dispatch(expr, std::dynamic_pointer_cast<LiteralDouble>(shared_from_this()), token);
}

std::shared_ptr<Expression> LiteralDouble::process(Token token)
{
    return OperationsDispatcher::dispatch(std::dynamic_pointer_cast<LiteralDouble>(shared_from_this()), token);
}

std::ostream& operator<<(std::ostream& os, const std::shared_ptr<LiteralDouble> expr)
{
    os << expr->value;
    return os;
}

std::ostream& operator<<(std::ostream& os, const LiteralDouble& expr)
{
    os << expr.value;
    return os;
}
