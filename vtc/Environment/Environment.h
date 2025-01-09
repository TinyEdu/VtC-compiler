#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H

#include "SymbolTable.h"


class Callable;

class Expression;

class Environment {
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

    template <typename T>
    T lookup(const std::string& name);

private:
    [[nodiscard]] Expression* lookupExpression(const std::string& name) const;

    [[nodiscard]] Callable* lookupCallable(const std::string& name) const;
};

#endif  // ENVIRONMENT_H
