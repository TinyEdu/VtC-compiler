// SymbolTable.h

#ifndef SYMBOLTABLE_H
#define SYMBOLTABLE_H

#include <map>
#include <string>

// Template class for managing symbol tables
template <typename T>
class SymbolTable {
public:
  // Default constructor
  SymbolTable();

  // Destructor
  ~SymbolTable();

  // Define a new symbol in the table
  void define(const std::string& name, T value);

  T lookup(const std::string& name) const;

  void assign(const std::string& name, T value);

private:
  std::map<std::string, T> env;
};


#endif  // SYMBOLTABLE_H
