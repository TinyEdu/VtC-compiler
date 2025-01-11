#include "Unary.h"

#include "Visitor/Visitor.h"

Unary::Unary(Token op, std::shared_ptr<Expression> right) : op(op), right(right)
{
}

std::shared_ptr<Expression> Unary::accept(Visitor& visitor)
{
    return visitor.visit(shared_from_this());
}

bool Unary::equals(const Expression& other) const
{
    const auto* otherUnary = dynamic_cast<const Unary*>(&other);
    if (otherUnary == nullptr)
    {
        return false;
    }

    // Compare `op` and `right` fields
    return this->op == otherUnary->op && // Compare operator tokens
    ((this->right == nullptr && otherUnary->right == nullptr) ||
        (this->right != nullptr && otherUnary->right != nullptr &&
            *this->right == *otherUnary->right)); // Recursively compare `right`
}


std::ostream& operator<<(std::ostream& os, const Unary* expr)
{
    os << expr->op << " " << expr->right;
    return os;
}

std::ostream& operator<<(std::ostream& os, const Unary& expr)
{
    os << expr.op << " " << expr.right;
    return os;
}
