#include "IfStatement.h"
#include "Visitor/Visitor.h"

std::any IfStatement::accept(StatementVisitor* visitor)
{
    return visitor->visit(this);
}