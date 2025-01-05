#include "ReturnStatement.h"
#include "Visitor/Visitor.h"

std::any ReturnStatement::accept(StatementVisitor* visitor)
{
    return visitor->visit(this);
}