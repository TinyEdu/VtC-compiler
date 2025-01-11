#include "ClassStatement.h"

#include <utility>
#include "Visitor/Visitor.h"

ClassStatement::ClassStatement(Token name, std::vector<std::shared_ptr<FunctionStatement>> methods)
    : name(std::move(name)), methods(std::move(methods))
{
}

ClassStatement::~ClassStatement() = default;

std::any ClassStatement::accept(StatementVisitor* visitor)
{
    return visitor->visit(shared_from_this());
}

bool ClassStatement::equals(const Statement& other) const
{
    // Use dynamic_cast with pointers to check if the type matches
    const auto* otherClassStmt = dynamic_cast<const ClassStatement*>(&other);
    if (!otherClassStmt)
    {
        return false;
    }

    // Compare the name token
    if (this->name != otherClassStmt->name)
    {
        return false;
    }

    // Compare the methods vector size
    if (this->methods.size() != otherClassStmt->methods.size())
    {
        return false;
    }

    // Compare each method in the methods vector
    for (size_t i = 0; i < this->methods.size(); ++i)
    {
        if (!(this->methods[i]->equals(*otherClassStmt->methods[i])))
        {
            return false;
        }
    }

    return true; // All statements matched
}
