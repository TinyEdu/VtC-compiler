#include "ReturnStatement.h"
#include "Visitor/Visitor.h"

ReturnStatement::ReturnStatement(Token keyword, std::shared_ptr<Expression> value)
    : keyword(std::move(keyword)), value(std::move(value))
{
}

ReturnStatement::~ReturnStatement() = default;

std::any ReturnStatement::accept(StatementVisitor* visitor)
{
    return visitor->visit(shared_from_this());
}

bool ReturnStatement::equals(const Statement& other) const
{
    const auto* otherReturn = dynamic_cast<const ReturnStatement*>(&other);
    if (!otherReturn)
    {
        return false;
    }

    return keyword == otherReturn->keyword &&
    ((!value && !otherReturn->value) ||
        (value && otherReturn->value && value->equals(*otherReturn->value)));
}
