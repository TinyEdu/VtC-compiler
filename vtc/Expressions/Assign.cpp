#include "Assign.h"

#include <utility>

#include "Visitor/Visitor.h"


Assign::Assign(Token name, std::shared_ptr<Expression> value) : name(name), value(std::move(value))
{
}

std::shared_ptr<Expression> Assign::accept(Visitor& visitor)
{
    return visitor.visit(shared_from_this());
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
