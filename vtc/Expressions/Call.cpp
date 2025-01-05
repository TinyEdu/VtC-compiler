#include "Call.h"

#include "Visitor/Visitor.h"

Call::Call(Expression* callee, Token paren, std::vector<Expression*> arguments)
    : callee(callee), paren(paren), arguments(arguments)
{
}

std::any Call::accept(Visitor* visitor) { return visitor->visit(this); }

bool Call::equals(const Expression& other) const
{
    const auto* otherCall = dynamic_cast<const Call*>(&other);
    if (otherCall == nullptr)
    {
        return false;
    }

    // Compare `callee`
    if ((this->callee == nullptr && otherCall->callee != nullptr) ||
        (this->callee != nullptr && otherCall->callee == nullptr) ||
        (this->callee != nullptr && otherCall->callee != nullptr && !(*this->callee == *otherCall->callee)))
    {
        return false;
    }

    // Compare `paren`
    if (this->paren != otherCall->paren)
    {
        return false;
    }

    // Compare `arguments`
    if (this->arguments.size() != otherCall->arguments.size())
    {
        return false;
    }

    for (size_t i = 0; i < this->arguments.size(); ++i)
    {
        if ((this->arguments[i] == nullptr && otherCall->arguments[i] != nullptr) ||
            (this->arguments[i] != nullptr && otherCall->arguments[i] == nullptr) ||
            (this->arguments[i] != nullptr && otherCall->arguments[i] != nullptr && !(*this->arguments[i] == *otherCall
                ->arguments[i])))
        {
            return false;
        }
    }

    return true;
}


std::ostream& operator<<(std::ostream& os, const Call& expr)
{
    os << "Call: " << expr.callee << " " << expr.paren;
    return os;
}

std::ostream& operator<<(std::ostream& os, const Call* expr)
{
    os << "Call: " << expr->callee << " " << expr->paren;
    return os;
}
