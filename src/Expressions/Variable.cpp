#include "Variable.h"

Variable::Variable(Token name) : name(name) {}

std::any Variable::accept(Visitor* visitor) {
  return visitor->visit(this);
}

std::ostream& operator<<(std::ostream& os, const Variable* expr) {
  os << expr->name;
  return os;
}

std::ostream& operator<<(std::ostream& os, const Variable& expr) {
  os << expr.name;
  return os;
}
