#include "FunctionStatement.h"

#include <utility>
#include "Visitor/Visitor.h"

FunctionStatement::FunctionStatement(Token name, std::vector<Token> params,
                                     std::vector<std::shared_ptr<Statement>> body)
    : name(std::move(name)), params(std::move(params)), body(std::move(body))
{
}

FunctionStatement::~FunctionStatement() = default;

std::any FunctionStatement::accept(StatementVisitor* visitor)
{
    return visitor->visit(shared_from_this());
}

bool FunctionStatement::equals(const Statement& other) const
{
    // Use dynamic_cast to check type and cast to FunctionStatement
    const auto* otherFunction = dynamic_cast<const FunctionStatement*>(&other);
    if (!otherFunction)
    {
        return false;
    }

    // Compare the name tokens
    if (this->name != otherFunction->name)
    {
        return false;
    }

    // Compare the parameters
    if (this->params != otherFunction->params)
    {
        return false;
    }

    // Compare the body statements
    if (this->body.size() != otherFunction->body.size())
    {
        return false;
    }

    for (size_t i = 0; i < this->body.size(); ++i)
    {
        // Ensure both statements are non-null and compare them
        if (!this->body[i] || !otherFunction->body[i])
        {
            return false; // Null pointer mismatch
        }

        if (!this->body[i]->equals(*otherFunction->body[i]))
        {
            return false; // Statements don't match
        }
    }

    return true; // All fields match
}
