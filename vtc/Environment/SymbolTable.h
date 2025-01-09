#ifndef SYMBOLTABLE_H
#define SYMBOLTABLE_H

#include <map>
#include <string>
#include "EnvironmentException.h"

// Template class for managing symbol tables
template <typename T>
class SymbolTable {
public:
  // Default constructor
  SymbolTable() = default;

  // Destructor
  ~SymbolTable() = default;

  // Define a new symbol in the table
  void define(const std::string& name, T value) {
    env[name] = value;
  }

  // Lookup a symbol in the table
  T lookup(const std::string& name) const {
    auto it = env.find(name);
    return (it != env.end()) ? it->second : nullptr;
  }

  // Assign a new value to an existing symbol
  void assign(const std::string& name, T value) {
    auto it = env.find(name);
    if (it != env.end()) {
      it->second = value;
    } else {
      throw EnvironmentException("Attempted to assign to undefined symbol: " + name);
    }
  }

private:
  std::map<std::string, T> env;
};

#endif  // SYMBOLTABLE_H
