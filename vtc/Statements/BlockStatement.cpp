#include "BlockStatement.h"

#include <utility>
#include "Visitor/Visitor.h"

BlockStatement::BlockStatement(std::vector<std::shared_ptr<Statement>> statements)
    : statements(std::move(statements))
{
}

BlockStatement::~BlockStatement() = default;

std::any BlockStatement::accept(StatementVisitor* visitor)
{
    return visitor->visit(shared_from_this());
}

bool BlockStatement::equals(const Statement& other) const
{
    // Use dynamic_cast to check type and cast to BlockStatement
    const auto* otherBlock = dynamic_cast<const BlockStatement*>(&other);
    if (!otherBlock)
    {
        return false;
    }

    // Compare sizes of `statements` vectors
    if (this->statements.size() != otherBlock->statements.size())
    {
        return false;
    }

    // Compare each statement in the vectors
    for (size_t i = 0; i < this->statements.size(); ++i)
    {
        // Ensure both statements are non-null and compare them
        if (!this->statements[i] || !otherBlock->statements[i])
        {
            return false; // Null pointer mismatch
        }
        if (!this->statements[i]->equals(*otherBlock->statements[i]))
        {
            return false; // Statements don't match
        }
    }

    return true; // All statements matched
}
