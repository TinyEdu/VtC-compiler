#include "VarStatement.h"
#include "Visitor/Visitor.h"

std::any VarStatement::accept(StatementVisitor* visitor)
{
    return visitor->visit(this);
}