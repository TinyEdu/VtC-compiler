#include "Logical.h"

#include "Visitor/Visitor.h"

Logical::Logical(Expression* left, Token op, Expression* right)
    : left(left), op(op), right(right)
{
}

std::any Logical::accept(Visitor* visitor)
{
    return visitor->visit(this);
}

bool Logical::equals(const Expression& other) const
{
    const auto* otherLogical = dynamic_cast<const Logical*>(&other);
    if (otherLogical == nullptr)
    {
        return false;
    }

    // Compare `left`, `op`, and `right` fields
    return ((this->left == nullptr && otherLogical->left == nullptr) ||
            (this->left != nullptr && otherLogical->left != nullptr &&
                *this->left == *otherLogical->left)) && // Compare left expressions
        this->op == otherLogical->op && // Compare operator tokens
        ((this->right == nullptr && otherLogical->right == nullptr) ||
            (this->right != nullptr && otherLogical->right != nullptr &&
                *this->right == *otherLogical->right)); // Compare right expressions
}


std::ostream& operator<<(std::ostream& os, const Logical* expr)
{
    os << expr->left << " " << expr->op << " " << expr->right;
    return os;
}

std::ostream& operator<<(std::ostream& os, const Logical& expr)
{
    os << expr.left << " " << expr.op << " " << expr.right;
    return os;
}
