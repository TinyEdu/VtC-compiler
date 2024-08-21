#include "Grouping.h"

Grouping::Grouping(Expression* expression) : expression(expression) {}

std::any Grouping::accept(Visitor* visitor) {
  return visitor->visit(this);
}

std::ostream& operator<<(std::ostream& os, const Grouping* expr) {
  os << "(" << expr->expression << ")";
  return os;
}

std::ostream& operator<<(std::ostream& os, const Grouping& expr) {
  os << "(" << expr.expression << ")";
  return os;
}

