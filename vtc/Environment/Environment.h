#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H

#include "SymbolTable.h"

#include <any>
#include <memory>


class Callable;
class Expression;

class Environment
{
public:
    std::shared_ptr<SymbolTable<std::shared_ptr<Expression>>> globalVariables;
    std::shared_ptr<SymbolTable<std::shared_ptr<Expression>>> localVariables;
    std::shared_ptr<SymbolTable<std::shared_ptr<Callable>>> functions;
    Environment* enclosing = nullptr;

    Environment();
    explicit Environment(SymbolTable<std::shared_ptr<Expression>>& globalVars);


    ~Environment();

    void define(const std::string& name, std::shared_ptr<Expression>  value) const;
    void define(const std::string& name, std::shared_ptr<Callable> value) const;
    void defineGlobal(const std::string& name, std::shared_ptr<Expression>  value) const;


    void assign(const std::string& name, std::shared_ptr<Expression>  value) const;
    void assign(const std::string& name, std::shared_ptr<Callable>  value) const;

private:
    [[nodiscard]] std::shared_ptr<Expression> lookupExpression(const std::string& name) const;

    [[nodiscard]] std::shared_ptr<Callable> lookupCallable(const std::string& name) const;

public:
    // @TODO: could be improved
    template <typename T>
    [[nodiscard]] std::any lookup(const std::string& name) const
    {
        if constexpr (std::is_same_v<T, std::shared_ptr<Expression>>)
        {
            return lookupExpression(name);
        }
        else if constexpr (std::is_same_v<T, std::shared_ptr<Callable>>)
        {
            return lookupCallable(name);
        }

        throw EnvironmentException("Type mismatch for variable '" + name + "'. Expected type: " + typeid(T).name());
    }
};

#endif  // ENVIRONMENT_H
