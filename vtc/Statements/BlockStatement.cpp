#include "BlockStatement.h"
#include "Visitor/Visitor.h"

std::any BlockStatement::accept(StatementVisitor* visitor)
{
    return visitor->visit(this);
}