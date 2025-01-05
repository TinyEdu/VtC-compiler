#include "Variable.h"

#include "Visitor/Visitor.h"

Variable::Variable(Token name) : name(name)
{
}

std::any Variable::accept(Visitor* visitor)
{
    return visitor->visit(this);
}

bool Variable::equals(const Expression& other) const
{
    const auto* otherVariable = dynamic_cast<const Variable*>(&other);
    if (otherVariable == nullptr)
    {
        return false;
    }

    // Compare `name` field
    return this->name == otherVariable->name;
}


std::ostream& operator<<(std::ostream& os, const Variable* expr)
{
    os << expr->name;
    return os;
}

std::ostream& operator<<(std::ostream& os, const Variable& expr)
{
    os << expr.name;
    return os;
}
