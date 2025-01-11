#include "ExpressionStatement.h"
#include "Visitor/Visitor.h"

ExpressionStatement::ExpressionStatement(std::shared_ptr<Expression> expression)
    : expression(std::move(expression))
{
}

ExpressionStatement::~ExpressionStatement() = default;

std::any ExpressionStatement::accept(StatementVisitor* visitor)
{
    return visitor->visit(shared_from_this());
}

bool ExpressionStatement::equals(const Statement& other) const
{
    // Use dynamic_cast to check type and cast to ExpressionStatement
    const auto* otherExprStmt = dynamic_cast<const ExpressionStatement*>(&other);
    if (!otherExprStmt)
    {
        return false;
    }

    // Compare the `expression` fields
    if (!this->expression && !otherExprStmt->expression)
    {
        return true; // Both expressions are null
    }

    if (!this->expression || !otherExprStmt->expression)
    {
        return false; // One is null, the other is not
    }

    return this->expression->equals(*otherExprStmt->expression); // Compare expressions
}
