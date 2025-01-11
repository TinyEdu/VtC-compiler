#include "IfStatement.h"
#include "Visitor/Visitor.h"

IfStatement::IfStatement(std::shared_ptr<Expression> condition, std::shared_ptr<Statement> thenBranch,
                         std::shared_ptr<Statement> elseBranch)
    : condition(std::move(condition)), thenBranch(std::move(thenBranch)), elseBranch(std::move(elseBranch))
{
}

IfStatement::~IfStatement() = default;

std::any IfStatement::accept(StatementVisitor* visitor)
{
    return visitor->visit(shared_from_this());
}

bool IfStatement::equals(const Statement& other) const
{
    const auto* otherIfStmt = dynamic_cast<const IfStatement*>(&other);
    if (!otherIfStmt)
    {
        return false;
    }

    return ((!condition && !otherIfStmt->condition) ||
            (condition && otherIfStmt->condition && condition->equals(*otherIfStmt->condition))) &&
        ((!thenBranch && !otherIfStmt->thenBranch) ||
            (thenBranch && otherIfStmt->thenBranch && thenBranch->equals(*otherIfStmt->thenBranch))) &&
        ((!elseBranch && !otherIfStmt->elseBranch) ||
            (elseBranch && otherIfStmt->elseBranch && elseBranch->equals(*otherIfStmt->elseBranch)));
}
