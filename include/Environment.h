// Environment.h

#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H

#include <map>
#include <stdexcept>
#include <string>

class Expression;

class Environment {
 public:
  Environment();
  Environment(Environment* enclosing);
  ~Environment();

 public:
  void define(std::string name, Expression* value);
  Expression* lookup(std::string name);
  void assign(std::string name, Expression* value);
 private:
  // enclosing environment
  Environment* enclosing = nullptr;
public:
  std::map<std::string, Expression*> env;
};

#endif  // ENVIRONMENT_H