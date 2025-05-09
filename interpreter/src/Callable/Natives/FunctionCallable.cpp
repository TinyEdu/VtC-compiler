#include "FunctionCallable.h"

#include <utility>
#include "Interpreter/BaseInterpreter.h"
#include "Expressions/ExpressionsWorld.h"
#include "Environment/Environment.h"
#include "Statements/StatementsWorld.h"
#include "Callable/Return.h"

FunctionCallable::FunctionCallable(std::shared_ptr<FunctionStatement> declaration)
    : declaration(std::move(declaration)) {}

int FunctionCallable::arity()
{
    return static_cast<int>(declaration->params.size());
}

std::shared_ptr<Expression> FunctionCallable::call(BaseInterpreter& interpreter,
                                                  const std::vector<std::shared_ptr<Expression>>& arguments)
{
    auto environment = std::make_shared<Environment>(interpreter.environment->globalVariables,
                                                     interpreter.environment->functions);

    for (int i = 0; i < declaration->params.size(); i++)
    {
        environment->define(declaration->params[i].lexeme, arguments[i]);
    }

    try
    {
        interpreter.execute(declaration->body, environment);
    }
    catch (const Return& returnedValue)
    {
        return returnedValue.value;
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
