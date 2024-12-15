#include "Statement.h"
#include "Visitor/Visitor.h"

inline std::any ExpressionStatement::accept(StatementVisitor* visitor)
{
    return visitor->visit(this);
}

std::any IfStatement::accept(StatementVisitor* visitor)
{
    return visitor->visit(this);
}

std::any WhileStatement::accept(StatementVisitor* visitor)
{
    return visitor->visit(this);
}

std::any PrintStatement::accept(StatementVisitor* visitor)
{
    return visitor->visit(this);
}

std::any VarStatement::accept(StatementVisitor* visitor)
{
    return visitor->visit(this);
}

std::any BlockStatement::accept(StatementVisitor* visitor)
{
    return visitor->visit(this);
}

std::any FunctionStatement::accept(StatementVisitor* visitor)
{
    return visitor->visit(this);
}

std::any ClassStatement::accept(StatementVisitor* visitor)
{
    return visitor->visit(this);
}

std::any ReturnStatement::accept(StatementVisitor* visitor)
{
    return visitor->visit(this);
}
