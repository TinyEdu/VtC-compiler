#include "ClassStatement.h"

#include <utility>
#include "Visitor/Visitor.h"

ClassStatement::ClassStatement(Token name, std::vector<FunctionStatement*> methods): name(name),
    methods(std::move(methods))
{
}

ClassStatement::~ClassStatement()
{
}

std::any ClassStatement::accept(StatementVisitor* visitor)
{
    return visitor->visit(this);
}

bool ClassStatement::equals(const Statement& other) const
{
    const auto* otherClassStmt = dynamic_cast<const ClassStatement*>(&other);
    if (otherClassStmt == nullptr)
    {
        return false;
    }

    // Compare the name token
    if (this->name != otherClassStmt->name)
    {
        return false;
    }

    // Compare the methods vector
    if (this->methods.size() != otherClassStmt->methods.size())
    {
        return false;
    }

    for (size_t i = 0; i < this->methods.size(); ++i)
    {
        if (!(this->methods[i] == otherClassStmt->methods[i]))
        {
            return false;
        }
    }

    return true; // All statements matched
}
