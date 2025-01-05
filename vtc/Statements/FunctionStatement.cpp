#include "FunctionStatement.h"

#include <utility>
#include "Visitor/Visitor.h"

FunctionStatement::FunctionStatement(Token name, std::vector<Token> params, std::vector<Statement*> body):
    name(name), params(std::move(params)), body(std::move(body))
{
}

FunctionStatement::~FunctionStatement()
{
}

std::any FunctionStatement::accept(StatementVisitor* visitor)
{
    return visitor->visit(this);
}

bool FunctionStatement::equals(const Statement& other) const
{
    const auto* otherFunction = dynamic_cast<const FunctionStatement*>(&other);
    if (otherFunction == nullptr)
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
        if (*this->body[i] != *otherFunction->body[i])
        {
            return false;
        }
    }

    return true; // All fields match
}
