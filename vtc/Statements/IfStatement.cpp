#include "IfStatement.h"
#include "Visitor/Visitor.h"

IfStatement::IfStatement(Expression* condition, Statement* thenBranch, Statement* elseBranch): condition(condition),
    thenBranch(thenBranch), elseBranch(elseBranch)
{
}

IfStatement::~IfStatement()
{
}

std::any IfStatement::accept(StatementVisitor* visitor)
{
    return visitor->visit(this);
}

bool IfStatement::equals(const Statement& other) const
{
    const auto* otherIfStmt = dynamic_cast<const IfStatement*>(&other);
    if (otherIfStmt == nullptr)
    {
        return false;
    }

    return ((this->condition == nullptr && otherIfStmt->condition == nullptr) ||
            (this->condition != nullptr && otherIfStmt->condition != nullptr &&
                *this->condition == *otherIfStmt->condition)) &&
        ((this->thenBranch == nullptr && otherIfStmt->thenBranch == nullptr) ||
            (this->thenBranch != nullptr && otherIfStmt->thenBranch != nullptr &&
                *this->thenBranch == *otherIfStmt->thenBranch)) &&
        ((this->elseBranch == nullptr && otherIfStmt->elseBranch == nullptr) ||
            (this->elseBranch != nullptr && otherIfStmt->elseBranch != nullptr &&
                *this->elseBranch == *otherIfStmt->elseBranch));
}
