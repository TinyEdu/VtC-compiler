#include "Assign.h"

#include "Visitor/Visitor.h"

Assign::Assign(Token name, Expression* value) : name(name), value(value) {}

std::any Assign::accept(Visitor* visitor) {
  return visitor->visit(this);
}

std::ostream& operator<<(std::ostream& os, const Assign& expr) {
  os << "Assign: " << expr.name.lexeme << " = " << expr.value;
  return os;
}

std::ostream& operator<<(std::ostream& os, const Assign* expr) {
  os << "Assign: " << expr->name.lexeme << " = " << expr->value;
  return os;
}
