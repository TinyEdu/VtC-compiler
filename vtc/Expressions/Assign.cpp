#include "Assign.h"

#include "Visitor/Visitor.h"

Assign::Assign(Token name, Expression* value) : name(name), value(value)
{
}

std::any Assign::accept(Visitor* visitor)
{
    return visitor->visit(this);
}

bool Assign::equals(const Expression& other) const
{
    const auto* otherAssign = dynamic_cast<const Assign*>(&other);
    if (otherAssign == nullptr)
    {
        return false;
    }

    // Compare the `name` and `value` fields
    return this->name == otherAssign->name &&
    ((this->value == nullptr && otherAssign->value == nullptr) ||
        (this->value != nullptr && otherAssign->value != nullptr &&
            *this->value == *otherAssign->value));
}

std::ostream& operator<<(std::ostream& os, const Assign& expr)
{
    os << "Assign: " << expr.name.lexeme << " = " << expr.value;
    return os;
}

std::ostream& operator<<(std::ostream& os, const Assign* expr)
{
    os << "Assign: " << expr->name.lexeme << " = " << expr->value;
    return os;
}
