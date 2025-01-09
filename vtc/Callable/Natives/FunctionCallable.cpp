#include "FunctionCallable.h"

#include "Interpreter/Interpreter.h"
#include "Expressions/ExpressionsWorld.h"
#include "Environment/Environment.h"
#include "Statements/StatementsWorld.h"
#include "Callable/Return.h"


FunctionCallable::FunctionCallable(FunctionStatement* declaration): declaration(declaration)
{
}

int FunctionCallable::arity()
{
    return static_cast<int>(declaration->params.size());
}

std::any FunctionCallable::call(Interpreter* interpreter, std::span<Expression* const> arguments)
{
    auto* environment = new Environment(interpreter->environment->globalVariables);

    for (int i = 0; i < declaration->params.size(); i++)
    {
        environment->define(declaration->params[i].lexeme, arguments[i]);
    }

    try
    {
        interpreter->executeBlock(declaration->body, environment);
    }
    catch (const Return& returnedValue)
    {
        std::any result = returnedValue.value;
        return result;
    }

    return {};
}

std::ostream& operator<<(std::ostream& os, const FunctionCallable& expr)
{
    os << "FunctionCallable - " << expr.declaration->name.lexeme;
    return os;
}

std::ostream& operator<<(std::ostream& os, const FunctionCallable* expr)
{
    os << "FunctionCallable - " << expr->declaration->name.lexeme;
    return os;
}
