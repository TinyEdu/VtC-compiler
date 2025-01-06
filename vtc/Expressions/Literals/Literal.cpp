#include "Literal.h"

#include "Visitor/Visitor.h"

std::any Literal::accept(Visitor* visitor)
{
    return visitor->visit(this);
}

bool Literal::equals(const Expression& other) const
{
    const auto otherLiteral = dynamic_cast<const Literal*>(&other);
    if (otherLiteral == nullptr)
    {
        return false;
    }

    // Note: this is only for testing purpose, this is not a save code for production code
    auto eq = Token(TokenType::EQUAL_EQUAL);
    auto nonConstOtherLiteral = const_cast<Literal*>(otherLiteral);
    auto nonConstThis = const_cast<Literal*>(this);

    return nonConstThis->process(nonConstOtherLiteral, eq);
}
