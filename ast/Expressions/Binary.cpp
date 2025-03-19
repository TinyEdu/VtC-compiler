#include "Binary.h"

#include <utility>

#include "Visitor/Visitor.h"

Binary::Binary(std::shared_ptr<Expression> left, Token op, std::shared_ptr<Expression> right)
    : left(std::move(left)), op(op), right(std::move(right))
{
}

std::shared_ptr<Expression> Binary::accept(Visitor& visitor)
{
    return visitor.visit(shared_from_this());
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
