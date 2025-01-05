#include "VarStatement.h"
#include "Visitor/Visitor.h"

VarStatement::VarStatement(Token name, Expression* initializer): name(name), initializer(initializer)
{
}

VarStatement::~VarStatement()
{
}

std::any VarStatement::accept(StatementVisitor* visitor)
{
    return visitor->visit(this);
}

bool VarStatement::equals(const Statement& other) const
{
    const auto* otherVarStmt = dynamic_cast<const VarStatement*>(&other);
    if (otherVarStmt == nullptr)
    {
        return false;
    }

    // Compare the `name` and `initializer` fields
    return this->name == otherVarStmt->name &&
    ((this->initializer == nullptr && otherVarStmt->initializer == nullptr) ||
        (this->initializer != nullptr && otherVarStmt->initializer != nullptr &&
            *this->initializer == *otherVarStmt->initializer)); // Recursively compare `initializer`
}
