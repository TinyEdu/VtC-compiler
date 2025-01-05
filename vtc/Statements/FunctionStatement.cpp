#include "FunctionStatement.h"
#include "Visitor/Visitor.h"

std::any FunctionStatement::accept(StatementVisitor* visitor)
{
    return visitor->visit(this);
}