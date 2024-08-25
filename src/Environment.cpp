#include "Environment.h"
#include "Expression.h"
#include "LogManager.h"

Environment::Environment() {
  env = std::map<std::string, std::any>();
}

Environment::Environment(Environment* enclosing) : enclosing(enclosing) {}

Environment::~Environment() {}
