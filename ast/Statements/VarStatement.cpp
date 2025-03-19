#include "VarStatement.h"
#include "Visitor/Visitor.h"

VarStatement::VarStatement(Token name, std::shared_ptr<Expression> initializer)
    : name(std::move(name)), initializer(std::move(initializer))
{
}

VarStatement::~VarStatement() = default;

std::any VarStatement::accept(StatementVisitor* visitor)
{
    return visitor->visit(shared_from_this());
}

bool VarStatement::equals(const Statement& other) const
{
    const auto* otherVarStmt = dynamic_cast<const VarStatement*>(&other);
    if (!otherVarStmt)
    {
        return false;
    }

    if (name != otherVarStmt->name)
    {
        return false;
    }

    if (initializer && otherVarStmt->initializer)
    {
        return initializer->equals(*otherVarStmt->initializer);
    }

    return !initializer && !otherVarStmt->initializer;
}
