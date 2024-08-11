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
  ~Environment();

 public:
  void define(std::string name, Expression* value);
  Expression* lookup(std::string name);

 private:
  std::map<std::string, Expression*> env;
};

#endif  // ENVIRONMENT_H