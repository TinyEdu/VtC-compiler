#include "ExpressionStatement.h"
#include "Visitor/Visitor.h"

ExpressionStatement::ExpressionStatement(Expression* expression): expression(expression)
{
}

ExpressionStatement::~ExpressionStatement()
{
}

std::any ExpressionStatement::accept(StatementVisitor* visitor)
{
    return visitor->visit(this);
}

bool ExpressionStatement::equals(const Statement& other) const
{
    const auto* otherExprStmt = dynamic_cast<const ExpressionStatement*>(&other);
    if (otherExprStmt == nullptr)
    {
        return false;
    }

    // Compare the `expression` fields
    return ((this->expression == nullptr && otherExprStmt->expression == nullptr) ||
        (this->expression != nullptr && otherExprStmt->expression != nullptr &&
            *this->expression == *otherExprStmt->expression)); // Recursively compare `expression`
}
