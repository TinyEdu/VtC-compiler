#ifndef SYMBOLTABLE_H
#define SYMBOLTABLE_H

#include "EnvironmentException.h"

#include <map>
#include <string>

#include "NotFoundInScopeException.h"


template <typename T>
class SymbolTable
{
public:
  SymbolTable() = default;
  ~SymbolTable() = default;

  void define(const std::string& name, T value)
  {
    if (!value)
    {
      throw std::runtime_error("Attempting to define a null value in the environment");
    }

    env[name] = value;
  }

  T lookup(const std::string& name) const
  {
    auto it = env.find(name);

    if (it == env.end())
    {
      return nullptr;
    }

    return it->second;
  }

  void assign(const std::string& name, T value)
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

private:
  std::map<std::string, T> env;
};

#endif  // SYMBOLTABLE_H
