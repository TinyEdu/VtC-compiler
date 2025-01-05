#include "ExpressionStatement.h"
#include "Visitor/Visitor.h"

std::any ExpressionStatement::accept(StatementVisitor* visitor)
{
    return visitor->visit(this);
}