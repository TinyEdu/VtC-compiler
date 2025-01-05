#include "ClassStatement.h"
#include "Visitor/Visitor.h"

std::any ClassStatement::accept(StatementVisitor* visitor)
{
    return visitor->visit(this);
}