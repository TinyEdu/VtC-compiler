#include "Environment.h"
#include "EnvironmentException.h"

Environment::Environment() : globalVariables(new SymbolTable<Expression*>()),
                             localVariables(new SymbolTable<Expression*>()),
                             functions(new SymbolTable<Callable*>())
{
}


Environment::Environment(SymbolTable<Expression*>* globalVariables): globalVariables(globalVariables),
                                                                            localVariables(
                                                                                new SymbolTable<Expression*>()),
                                                                            functions(new SymbolTable<Callable*>())
{
}

Environment::~Environment()
{
    delete localVariables;
    delete globalVariables;
    delete functions;
}

void Environment::define(const std::string& name, Expression* value) const
{
    localVariables->define(name, value);
}

void Environment::defineGlobal(const std::string& name, Expression* value) const
{
    globalVariables->define(name, value);
}

void Environment::define(const std::string& name, Callable* value) const
{
    functions->define(name, value);
}

void Environment::assign(const std::string& name, Expression* value) const
{
    if (localVariables->lookup(name) != nullptr)
    {
        localVariables->assign(name, value);
        return;
    }
    if (enclosing != nullptr)
    {
        enclosing->assign(name, value);
        return;
    }
    throw EnvironmentException("Undefined variable '" + name + "'.");
}

void Environment::assign(const std::string& name, Callable* value) const
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
    throw EnvironmentException("Undefined variable '" + name + "'.");
}


Expression* Environment::lookupExpression(const std::string& name) const
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

Callable* Environment::lookupCallable(const std::string& name) const
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
