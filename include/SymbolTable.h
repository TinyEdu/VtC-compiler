// SymbolTable.h

#ifndef SYMBOLTABLE_H 
#define SYMBOLTABLE_H

#include <iostream>
#include <map>
#include <stdexcept>
#include <string>


template <typename T>
class SymbolTable {
 public:
  SymbolTable() {};
  ~SymbolTable() {};

  void define(const std::string& name, T value) {
    env[name] = value;
  }

  // Lookup a variable in the environment
  T lookup(const std::string& name) {
    if (env.find(name) != env.end()) {
        return env[name];
    }

    return nullptr;
  }

  // Assign a value to a variable in the environment
  void assign(const std::string& name, T value) {
    if (env.find(name) != env.end()) {
      env[name] = value;
    }
  }

 private:
  std::map<std::string, T> env;
};

#endif  // SYMBOLTABLE_H 
