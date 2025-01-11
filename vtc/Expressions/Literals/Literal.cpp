#include "Literal.h"

#include "Visitor/Visitor.h"

bool Literal::equals(const Expression& other) const
{
    // Try to cast the other Expression to a Literal
    const auto* otherLiteral = dynamic_cast<const Literal*>(&other);
    if (!otherLiteral)
    {
        return false;
    }

    Token eq(TokenType::EQUAL_EQUAL);

    // Use concrete type when creating the shared pointer
    auto* nonConstOtherLiteral = const_cast<Literal*>(otherLiteral);
    auto* nonConstThis = const_cast<Literal*>(this);

    // Determine the concrete type of the Literal and create the appropriate shared pointer
    std::shared_ptr<Literal> s;
    if (auto* literalInt = dynamic_cast<LiteralInt*>(nonConstOtherLiteral))
    {
        s = std::make_shared<LiteralInt>(*literalInt);
    }
    else if (auto* literalBool = dynamic_cast<LiteralBool*>(nonConstOtherLiteral))
    {
        s = std::make_shared<LiteralBool>(*literalBool);
    }
    else if (auto* literalDouble = dynamic_cast<LiteralDouble*>(nonConstOtherLiteral))
    {
        s = std::make_shared<LiteralDouble>(*literalDouble);
    }
    else if (auto* literalString = dynamic_cast<LiteralString*>(nonConstOtherLiteral))
    {
        s = std::make_shared<LiteralString>(*literalString);
    }
    else
    {
        throw std::runtime_error("Unsupported Literal type in equals()");
    }

    // Call process using the shared pointer of the appropriate type
    return nonConstThis->process(s, eq)->equals(*this);
}
