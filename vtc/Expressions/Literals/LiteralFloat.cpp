#include "LiteralFloat.h"

#include "Visitor/OperationsDispatcher.h"
#include "Visitor/Visitor.h"


LiteralFloat::LiteralFloat(float value): value(value)
{
}

std::shared_ptr<Expression> LiteralFloat::accept(Visitor& visitor)
{
    return visitor.visit(std::dynamic_pointer_cast<LiteralFloat>(shared_from_this()));
}

std::shared_ptr<Expression> LiteralFloat::process(std::shared_ptr<Literal> expr, Token token)
{
    return expr->process(std::dynamic_pointer_cast<LiteralFloat>(shared_from_this()), token);
}

std::shared_ptr<Expression> LiteralFloat::process(std::shared_ptr<LiteralInt> expr, Token token)
{
    return OperationsDispatcher::dispatch(expr, std::dynamic_pointer_cast<LiteralFloat>(shared_from_this()), token);
};

std::shared_ptr<Expression> LiteralFloat::process(std::shared_ptr<LiteralFloat> expr, Token token)
{
    return OperationsDispatcher::dispatch(expr, std::dynamic_pointer_cast<LiteralFloat>(shared_from_this()), token);
};

std::shared_ptr<Expression> LiteralFloat::process(std::shared_ptr<LiteralString> expr, Token token)
{
    return OperationsDispatcher::dispatch(expr, std::dynamic_pointer_cast<LiteralFloat>(shared_from_this()), token);
};

std::shared_ptr<Expression> LiteralFloat::process(std::shared_ptr<LiteralBool> expr, Token token)
{
    return OperationsDispatcher::dispatch(expr, std::dynamic_pointer_cast<LiteralFloat>(shared_from_this()), token);
};

std::shared_ptr<Expression> LiteralFloat::process(std::shared_ptr<LiteralDouble> expr, Token token)
{
    return OperationsDispatcher::dispatch(expr, std::dynamic_pointer_cast<LiteralFloat>(shared_from_this()), token);
};

std::shared_ptr<Expression> LiteralFloat::process(Token token)
{
    return OperationsDispatcher::dispatch(std::dynamic_pointer_cast<LiteralFloat>(shared_from_this()), token);
}

std::ostream& operator<<(std::ostream& os, const std::shared_ptr<LiteralFloat> expr)
{
    os << expr->value;
    return os;
}

std::ostream& operator<<(std::ostream& os, const LiteralFloat& expr)
{
    os << expr.value;
    return os;
}
