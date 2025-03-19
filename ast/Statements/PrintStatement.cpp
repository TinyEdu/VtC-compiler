#include "PrintStatement.h"
#include "Visitor/Visitor.h"

PrintStatement::PrintStatement(std::shared_ptr<Expression> expression)
    : expression(std::move(expression))
{
}

PrintStatement::~PrintStatement() = default;

std::any PrintStatement::accept(StatementVisitor* visitor)
{
    return visitor->visit(shared_from_this());
}

bool PrintStatement::equals(const Statement& other) const
{
    const auto* otherPrintStmt = dynamic_cast<const PrintStatement*>(&other);
    if (!otherPrintStmt)
    {
        return false;
    }

    return ((!expression && !otherPrintStmt->expression) ||
        (expression && otherPrintStmt->expression && expression->equals(*otherPrintStmt->expression)));
}
