#include "WhileStatement.h"
#include "Visitor/Visitor.h"

WhileStatement::WhileStatement(Expression* condition, Statement* body): condition(condition), body(body)
{
}

WhileStatement::~WhileStatement()
{
}

std::any WhileStatement::accept(StatementVisitor* visitor)
{
    return visitor->visit(this);
}

bool WhileStatement::equals(const Statement& other) const
{
    const auto* otherWhileStmt = dynamic_cast<const WhileStatement*>(&other);
    if (otherWhileStmt == nullptr)
    {
        return false;
    }

    return ((this->condition == nullptr && otherWhileStmt->condition == nullptr) ||
            (this->condition != nullptr && otherWhileStmt->condition != nullptr &&
                *this->condition == *otherWhileStmt->condition)) && // Compare conditions
        ((this->body == nullptr && otherWhileStmt->body == nullptr) ||
            (this->body != nullptr && otherWhileStmt->body != nullptr &&
                *this->body == *otherWhileStmt->body)); // Compare bodies
}
