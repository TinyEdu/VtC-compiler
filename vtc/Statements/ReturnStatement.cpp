#include "ReturnStatement.h"
#include "Visitor/Visitor.h"

ReturnStatement::ReturnStatement(Token keyword, Expression* value): keyword(keyword), value(value)
{
}

ReturnStatement::~ReturnStatement()
{
}

std::any ReturnStatement::accept(StatementVisitor* visitor)
{
    return visitor->visit(this);
}

bool ReturnStatement::equals(const Statement& other) const
{
    const auto* otherReturn = dynamic_cast<const ReturnStatement*>(&other);
    if (otherReturn == nullptr)
    {
        return false;
    }

    return this->keyword == otherReturn->keyword &&
    ((this->value == nullptr && otherReturn->value == nullptr) ||
        (this->value != nullptr && otherReturn->value != nullptr &&
            *this->value == *otherReturn->value)); // Recursively compare `value`
}
