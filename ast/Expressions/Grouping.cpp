#include "Grouping.h"

#include "Visitor/Visitor.h"

Grouping::Grouping(std::shared_ptr<Expression> expression) : expression(expression)
{
}

std::shared_ptr<Expression> Grouping::accept(Visitor& visitor)
{
    return visitor.visit(shared_from_this());
}

bool Grouping::equals(const Expression& other) const
{
    const auto* otherGrouping = dynamic_cast<const Grouping*>(&other);
    if (otherGrouping == nullptr)
    {
        return false;
    }

    // Compare the `expression` field
    return (this->expression == nullptr && otherGrouping->expression == nullptr) ||
    (this->expression != nullptr && otherGrouping->expression != nullptr &&
        *this->expression == *otherGrouping->expression);
}


std::ostream& operator<<(std::ostream& os, const Grouping* expr)
{
    os << "(" << expr->expression << ")";
    return os;
}

std::ostream& operator<<(std::ostream& os, const Grouping& expr)
{
    os << "(" << expr.expression << ")";
    return os;
}
