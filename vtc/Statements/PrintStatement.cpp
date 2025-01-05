#include "PrintStatement.h"
#include "Visitor/Visitor.h"

PrintStatement::PrintStatement(Expression* expression): expression(expression)
{
}

PrintStatement::~PrintStatement()
{
}

std::any PrintStatement::accept(StatementVisitor* visitor)
{
    return visitor->visit(this);
}

bool PrintStatement::equals(const Statement& other) const
{
    const auto* otherPrintStmt = dynamic_cast<const PrintStatement*>(&other);
    if (otherPrintStmt == nullptr)
    {
        return false;
    }

    // Compare the `expression` fields
    return ((this->expression == nullptr && otherPrintStmt->expression == nullptr) ||
        (this->expression != nullptr && otherPrintStmt->expression != nullptr &&
            *this->expression == *otherPrintStmt->expression));
}
