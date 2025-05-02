#include "Environment.h"
#include "EnvironmentException.h"

Environment::Environment()
    : globalVariables(std::make_shared<SymbolTable<std::shared_ptr<Expression>>>()),
      localVariables(std::make_shared<SymbolTable<std::shared_ptr<Expression>>>()),
      functions(std::make_shared<SymbolTable<std::shared_ptr<Callable>>>())
{
}

Environment::Environment(std::shared_ptr<Environment> enclosingEnv)
    : globalVariables(enclosingEnv
                          ? enclosingEnv->globalVariables
                          : std::make_shared<SymbolTable<std::shared_ptr<Expression>>>()),
      localVariables(std::make_shared<SymbolTable<std::shared_ptr<Expression>>>()),
      functions(enclosingEnv
                    ? enclosingEnv->functions
                    : std::make_shared<SymbolTable<std::shared_ptr<Callable>>>()),
      enclosing(std::move(enclosingEnv))
{
}


Environment::Environment(const std::shared_ptr<SymbolTable<std::shared_ptr<Expression>>>& globalVars)
    : globalVariables(std::make_shared<SymbolTable<std::shared_ptr<Expression>>>(*globalVars)),
      localVariables(std::make_shared<SymbolTable<std::shared_ptr<Expression>>>()),
      functions(std::make_shared<SymbolTable<std::shared_ptr<Callable>>>())
{
}

Environment::Environment(const std::shared_ptr<SymbolTable<std::shared_ptr<Expression>>>& globalVars,
                         const std::shared_ptr<SymbolTable<std::shared_ptr<Callable>>>& functions)
    : globalVariables(std::make_shared<SymbolTable<std::shared_ptr<Expression>>>(*globalVars)),
      localVariables(std::make_shared<SymbolTable<std::shared_ptr<Expression>>>()),
      functions(std::make_shared<SymbolTable<std::shared_ptr<Callable>>>(*functions))
{
}

Environment::~Environment() = default;

void Environment::define(const std::string& name, std::shared_ptr<Expression> value) const
{
    if (enclosing == nullptr)
    {
        globalVariables->define(name, value);
    }
    else // Local scope
    {
        localVariables->define(name, value);
    }
}

void Environment::defineGlobal(const std::string& name, std::shared_ptr<Expression> value) const
{
    globalVariables->define(name, value);
}

void Environment::define(const std::string& name, std::shared_ptr<Callable> value) const
{
    functions->define(name, value);
}

void Environment::assign(const std::string& name, std::shared_ptr<Expression> value) const
{
    if (localVariables->lookup(name) != nullptr)
    {
        localVariables->assign(name, value);
        return;
    }
    if (globalVariables->lookup(name) != nullptr)
    {
        globalVariables->assign(name, value);
        return;
    }
    if (enclosing != nullptr)
    {
        enclosing->assign(name, value);
        return;
    }
    throw EnvironmentException("Undefined variable '" + name + "'.");
}

void Environment::assign(const std::string& name, std::shared_ptr<Callable> value) const
{
    if (functions->lookup(name) != nullptr)
    {
        functions->assign(name, value);
        return;
    }
    if (enclosing != nullptr)
    {
        enclosing->assign(name, value);
        return;
    }
    throw EnvironmentException("Undefined Callable '" + name + "'.");
}

std::shared_ptr<Expression> Environment::lookupExpression(const std::string& name) const
{
    if (localVariables->lookup(name) != nullptr)
    {
        return localVariables->lookup(name);
    }
    if (globalVariables->lookup(name) != nullptr)
    {
        return globalVariables->lookup(name);
    }
    if (enclosing != nullptr)
    {
        return enclosing->lookupExpression(name);
    }

    throw EnvironmentException("Undefined variable '" + name + "'.");
}

std::shared_ptr<Callable> Environment::lookupCallable(const std::string& name) const
{
    if (functions->lookup(name) != nullptr)
    {
        return functions->lookup(name);
    }
    if (enclosing != nullptr)
    {
        return enclosing->lookupCallable(name);
    }
    throw EnvironmentException("Undefined Callable '" + name + "'.");
}
