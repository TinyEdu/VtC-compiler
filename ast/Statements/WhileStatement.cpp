#include "WhileStatement.h"
#include "Visitor/Visitor.h"

WhileStatement::WhileStatement(std::shared_ptr<Expression> condition, std::shared_ptr<Statement> body)
    : condition(std::move(condition)), body(std::move(body))
{
}

WhileStatement::~WhileStatement() = default;

std::any WhileStatement::accept(StatementVisitor* visitor)
{
    return visitor->visit(shared_from_this());
}

bool WhileStatement::equals(const Statement& other) const
{
    const auto* otherWhileStmt = dynamic_cast<const WhileStatement*>(&other);
    if (!otherWhileStmt)
    {
        return false;
    }

    return ((!condition && !otherWhileStmt->condition) ||
            (condition && otherWhileStmt->condition && condition->equals(*otherWhileStmt->condition))) &&
        ((!body && !otherWhileStmt->body) ||
            (body && otherWhileStmt->body && body->equals(*otherWhileStmt->body)));
}
