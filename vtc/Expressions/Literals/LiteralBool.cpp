#include "LiteralBool.h"
#include "Expressions/Literals/LiteralDouble.h"

#include "Visitor/OperationsDispatcher.h"
#include "Visitor/Visitor.h"

LiteralBool::LiteralBool(bool value): value(value)
{
}

std::shared_ptr<Expression> LiteralBool::accept(Visitor& visitor)
{
    return visitor.visit(shared_from_this());
}

std::shared_ptr<Expression> LiteralBool::process(std::shared_ptr<Literal> expr, Token token)
{
    return expr->process(shared_from_this(), token);
}

std::shared_ptr<Expression> LiteralBool::process(std::shared_ptr<LiteralInt> expr, Token token)
{
    return
        OperationsDispatcher::dispatch(expr, std::dynamic_pointer_cast<LiteralBool>(shared_from_this()), token);
};

std::shared_ptr<Expression> LiteralBool::process(std::shared_ptr<LiteralFloat> expr, Token token)
{
    return OperationsDispatcher::dispatch(expr, std::dynamic_pointer_cast<LiteralBool>(shared_from_this()), token);
};

std::shared_ptr<Expression> LiteralBool::process(std::shared_ptr<LiteralString> expr, Token token)
{
    return OperationsDispatcher::dispatch(expr, std::dynamic_pointer_cast<LiteralBool>(shared_from_this()), token);
};

std::shared_ptr<Expression> LiteralBool::process(std::shared_ptr<LiteralBool> expr, Token token)
{
    return OperationsDispatcher::dispatch(expr, std::dynamic_pointer_cast<LiteralBool>(shared_from_this()), token);
};

std::shared_ptr<Expression> LiteralBool::process(std::shared_ptr<LiteralDouble> expr, Token token)
{
    return OperationsDispatcher::dispatch(expr, std::dynamic_pointer_cast<LiteralBool>(shared_from_this()), token);
};

std::shared_ptr<Expression> LiteralBool::process(Token token)
{
    return OperationsDispatcher::dispatch(std::dynamic_pointer_cast<LiteralBool>(shared_from_this()), token);
}

std::ostream& operator<<(std::ostream& os, const std::shared_ptr<LiteralBool> expr)
{
    os << expr->value;
    return os;
}

std::ostream& operator<<(std::ostream& os, const LiteralBool& expr)
{
    os << expr.value;
    return os;
}
