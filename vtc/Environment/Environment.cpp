#include "Environment.h"
#include "EnvironmentException.h"

inline Environment::Environment(): globalVariables(new SymbolTable<Expression*>()),
                                   localVariables(new SymbolTable<Expression*>()),
                                   functions(new SymbolTable<Callable*>())
{
}

inline Environment::Environment(SymbolTable<Expression*>* globalVariables): globalVariables(globalVariables),
                                                                            localVariables(
                                                                                new SymbolTable<Expression*>()),
                                                                            functions(new SymbolTable<Callable*>())
{
}

inline Environment::~Environment()
{
    delete localVariables;
    delete globalVariables;
    delete functions;
}

inline void Environment::define(const std::string& name, Expression* value) const
{
    localVariables->define(name, value);
}

inline void Environment::defineGlobal(const std::string& name, Expression* value) const
{
    globalVariables->define(name, value);
}

inline void Environment::define(const std::string& name, Callable* value) const
{
    functions->define(name, value);
}

inline void Environment::assign(const std::string& name, Expression* value) const
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

inline void Environment::assign(const std::string& name, Callable* value) const
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

template <typename T>
T Environment::lookup(const std::string& name)
{
    if constexpr (std::is_same_v<T, Expression*>)
    {
        return lookupExpression(name);
    }
    else if constexpr (std::is_same_v<T, Callable*>)
    {
        return lookupCallable(name);
    }
    throw EnvironmentException("Type mismatch for variable '" + name + "'. Expected type: " + typeid(T).name());
}

inline Expression* Environment::lookupExpression(const std::string& name) const
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

inline Callable* Environment::lookupCallable(const std::string& name) const
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
