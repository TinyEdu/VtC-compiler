// Environment.h
#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H

#include <SymbolTable.h>
#include <typeinfo>

class Callable;
class Expression;

class Environment {
public:
    Environment() : localVariables(new SymbolTable<Expression*>()), globalVariables(new SymbolTable<Expression*>()), functions(new SymbolTable<Callable*>()), enclosing(nullptr) {}

    Environment(SymbolTable<Expression*>* globalVariables) 
        : localVariables(new SymbolTable<Expression*>()), globalVariables(globalVariables), functions(new SymbolTable<Callable*>()) {}

    ~Environment() {
        delete localVariables;
        delete globalVariables;
        delete functions;
    }

    void define(const std::string& name, Expression* value) {
        localVariables->define(name, value);
    };

    void defineGlobal(const std::string& name, Expression* value) {
        globalVariables->define(name, value);
    };

    void define(const std::string& name, Callable* value) {
        functions->define(name, value);
    };

    void assign(const std::string& name, Expression* value) {
        if (localVariables->lookup(name) != nullptr) {
            localVariables->assign(name, value);
            return;
        }

        if (enclosing != nullptr) {
            enclosing->assign(name, value);
            return;
        }

        throw std::runtime_error("Undefined variable '" + name + "'.");
    }

    void assign(const std::string& name, Callable* value) {
        if (functions->lookup(name) != nullptr) {
            functions->assign(name, value);
            return;
        }

        if (enclosing != nullptr) {
            functions->assign(name, value);
            return;
        }
        
        throw std::runtime_error("Undefined variable '" + name + "'.");
    }

    template <typename T>
    T lookup(const std::string& name) {
        // if T == Expression*
        if constexpr (std::is_same<T, Expression*>::value) {
            return lookupExpression(name);
        }
        else if constexpr (std::is_same<T, Callable*>::value) {
            return lookupCallable(name);
        }

        throw std::runtime_error("Type mismatch for variable '" + name + "'. Expected type: " + typeid(T).name());
    }

private:
    Expression* lookupExpression(const std::string& name) {
        if (localVariables->lookup(name) != nullptr) {
            return localVariables->lookup(name);
        }

        if (globalVariables->lookup(name) != nullptr) {
            return globalVariables->lookup(name);
        }

        if (enclosing != nullptr) {
            return enclosing->lookupExpression(name);
        }

        throw std::runtime_error("Undefined variable '" + name + "'.");
    }

    Callable* lookupCallable(const std::string& name) {
        if (functions->lookup(name) != nullptr) {
            return functions->lookup(name);
        }

        if (enclosing != nullptr) {
            return enclosing->lookupCallable(name);
        }

        throw std::runtime_error("Undefined variable '" + name + "'.");
    }

public:
    // used to store global variables
    SymbolTable<Expression*>* globalVariables;
private:
    // used for storing variables
    SymbolTable<Expression*>* localVariables;

    // used for storing functions
    SymbolTable<Callable*>* functions;

    Environment* enclosing;
};

#endif  // ENVIRONMENT_H