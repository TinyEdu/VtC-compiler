#include "PrintStatement.h"
#include "Visitor/Visitor.h"

std::any PrintStatement::accept(StatementVisitor* visitor)
{
    return visitor->visit(this);
}