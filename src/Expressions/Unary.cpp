#include "Unary.h"

Unary::Unary(Token op, Expression* right) : op(op), right(right) {}

std::any Unary::accept(Visitor* visitor) {
  return visitor->visit(this);
}

std::ostream& operator<<(std::ostream& os, const Unary* expr) {
  os << expr->op << " " << expr->right;
  return os;
}

std::ostream& operator<<(std::ostream& os, const Unary& expr) {
  os << expr.op << " " << expr.right;
  return os;
}
