#include "WhileStatement.h"
#include "Visitor/Visitor.h"

std::any WhileStatement::accept(StatementVisitor* visitor)
{
    return visitor->visit(this);
}