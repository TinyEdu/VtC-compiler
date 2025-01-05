#include "Binary.h"

#include "Visitor/Visitor.h"

Binary::Binary(Expression* left, Token op, Expression* right)
    : left(left), op(op), right(right)
{
}

std::any Binary::accept(Visitor* visitor)
{
    return visitor->visit(this);
}

bool Binary::equals(const Expression& other) const
{
    const auto* otherBinary = dynamic_cast<const Binary*>(&other);
    if (otherBinary == nullptr)
    {
        return false;
    }

    // Compare `left`, `op`, and `right` fields
    return ((this->left == nullptr && otherBinary->left == nullptr) ||
            (this->left != nullptr && otherBinary->left != nullptr &&
                *this->left == *otherBinary->left)) && // Compare left expressions
        this->op == otherBinary->op && // Compare operator tokens
        ((this->right == nullptr && otherBinary->right == nullptr) ||
            (this->right != nullptr && otherBinary->right != nullptr &&
                *this->right == *otherBinary->right)); // Compare right expressions
}

std::ostream& operator<<(std::ostream& os, const Binary* expr)
{
    os << expr->left << " " << expr->op << " " << expr->right;
    return os;
}

std::ostream& operator<<(std::ostream& os, const Binary& expr)
{
    os << expr.left << " " << expr.op << " " << expr.right;
    return os;
}
