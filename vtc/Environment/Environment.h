#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H

#include "SymbolTable.h"


class Callable;

class Expression;

class Environment
{
public:
    SymbolTable<Expression*>* globalVariables = nullptr;
    SymbolTable<Expression*>* localVariables = nullptr;
    SymbolTable<Callable*>* functions = nullptr;
    Environment* enclosing = nullptr;

    Environment();

    explicit Environment(SymbolTable<Expression*>* globalVariables);

    ~Environment();

    void define(const std::string& name, Expression* value) const;
    void define(const std::string& name, Callable* value) const;
    void defineGlobal(const std::string& name, Expression* value) const;


    void assign(const std::string& name, Expression* value) const;
    void assign(const std::string& name, Callable* value) const;

private:
    [[nodiscard]] Expression* lookupExpression(const std::string& name) const;

    [[nodiscard]] Callable* lookupCallable(const std::string& name) const;

public:
    template <typename T>
    T lookup(const std::string& name)
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
};

#endif  // ENVIRONMENT_H
