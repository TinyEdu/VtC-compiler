// Environment.h

#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H

#include <map>
#include <stdexcept>
#include <string>

#include <functional>
#include <any>


class Expression;

class Environment {
 public:

  Environment();
  Environment(Environment* enclosing);
  ~Environment();

 public:
  void assign(std::string name, Expression* value);
  
  template <typename T>
  void define(std::string name, T value) {
    env[name] = value;
  }

  template <typename T>
  T lookup(std::string name) {
  // Check if the variable is defined in the current environment
  if (env.find(name) != env.end()) {
    return std::any_cast<T>(env[name]);
  }

  if (enclosing != nullptr) {
    // Recursively lookup in the enclosing environment
    return std::any_cast<T>(enclosing->lookup<T>(name));
  }

  throw std::runtime_error("Undefined variable '" + name + "'");
}


  template <typename T>
  void assign(std::string name, T value) {
      env[name] = value;
  }



 private:
  // enclosing environment
  Environment* enclosing = nullptr;

 public:
  std::map<std::string, std::any> env;
};

#endif  // ENVIRONMENT_H