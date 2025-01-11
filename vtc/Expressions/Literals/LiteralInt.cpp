#include "LiteralInt.h"

#include "Visitor/OperationsDispatcher.h"
#include "Visitor/Visitor.h"

LiteralInt::LiteralInt(int value): value(value)
{
}

std::shared_ptr<Expression> LiteralInt::accept(Visitor& visitor)
{
    return visitor.visit(std::dynamic_pointer_cast<LiteralBool>(shared_from_this()));
}

std::shared_ptr<Expression> LiteralInt::process(std::shared_ptr<Literal> expr, Token token)
{
    return expr->process(std::dynamic_pointer_cast<LiteralInt>(shared_from_this()), token);
}

std::shared_ptr<Expression> LiteralInt::process(std::shared_ptr<LiteralInt> expr, Token token)
{
    return OperationsDispatcher::dispatch(expr, std::dynamic_pointer_cast<LiteralInt>(shared_from_this()), token);
};

std::shared_ptr<Expression> LiteralInt::process(std::shared_ptr<LiteralFloat> expr, Token token)
{
    return OperationsDispatcher::dispatch(expr, std::dynamic_pointer_cast<LiteralInt>(shared_from_this()), token);
};

std::shared_ptr<Expression> LiteralInt::process(std::shared_ptr<LiteralString> expr, Token token)
{
    return OperationsDispatcher::dispatch(expr, std::dynamic_pointer_cast<LiteralInt>(shared_from_this()), token);
};

std::shared_ptr<Expression> LiteralInt::process(std::shared_ptr<LiteralBool> expr, Token token)
{
    return OperationsDispatcher::dispatch(expr, std::dynamic_pointer_cast<LiteralInt>(shared_from_this()), token);
};

std::shared_ptr<Expression> LiteralInt::process(std::shared_ptr<LiteralDouble> expr, Token token)
{
    return OperationsDispatcher::dispatch(expr, std::dynamic_pointer_cast<LiteralInt>(shared_from_this()), token);
};

std::shared_ptr<Expression> LiteralInt::process(Token token)
{
    return OperationsDispatcher::dispatch(std::dynamic_pointer_cast<LiteralInt>(shared_from_this()), token);
}

std::ostream& operator<<(std::ostream& os, const std::shared_ptr<LiteralInt> expr)
{
    os << expr->value;
    return os;
}

std::ostream& operator<<(std::ostream& os, const LiteralInt& expr)
{
    os << expr.value;
    return os;
}
