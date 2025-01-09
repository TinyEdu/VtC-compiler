#include "SymbolTable.h"
#include "EnvironmentException.h"

template <typename T>
SymbolTable<T>::SymbolTable() = default;

template <typename T>
SymbolTable<T>::~SymbolTable() = default;

template <typename T>
void SymbolTable<T>::define(const std::string& name, T value)
{
    env[name] = value;
}

template <typename T>
T SymbolTable<T>::lookup(const std::string& name) const
{
    auto it = env.find(name);
    return (it != env.end()) ? it->second : nullptr;
}

template <typename T>
void SymbolTable<T>::assign(const std::string& name, T value)
{
    auto it = env.find(name);
    if (it != env.end())
    {
        it->second = value;
    }
    else
    {
        throw EnvironmentException("Attempted to assign to undefined symbol: " + name);
    }
}
