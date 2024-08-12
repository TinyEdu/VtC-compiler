#include "Environment.h"
#include "LogManager.h"
#include "Expression.h"

Environment::Environment() {
  env = std::map<std::string, Expression*>();
}

Environment::Environment(Environment* enclosing) : enclosing(enclosing) {}

Environment::~Environment() {}

void Environment::define(std::string name, Expression* value) {
  env[name] = value;
}

Expression* Environment::lookup(std::string name) {
  // Check if the variable is defined in the current environment
  if (env.find(name) != env.end()) {
    return env[name];
  }

  if (enclosing != nullptr) {
    // Recursively lookup in the enclosing environment
    return enclosing->lookup(name);
  }

  throw std::runtime_error("Undefined variable '" + name + "'");
}

void Environment::assign(std::string name, Expression* value) {
    // Check if the variable is defined in the current environment
    if (env.find(name) != env.end()) {
        env[name] = value;
        return;
    }

    // If not, check if it is defined in the enclosing environment
    if (enclosing != nullptr) {
        enclosing->assign(name, value);
        return;
    }

    throw std::runtime_error("Undefined variable '" + name + "'");
}
