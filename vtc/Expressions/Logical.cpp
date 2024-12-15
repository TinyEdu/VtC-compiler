#include "Logical.h"

#include "Visitor/Visitor.h"

Logical::Logical(Expression* left, Token op, Expression* right)
    : left(left), op(op), right(right) {}

std::any Logical::accept(Visitor* visitor) {
  return visitor->visit(this);
}

std::ostream& operator<<(std::ostream& os, const Logical* expr) {
  os << expr->left << " " << expr->op << " " << expr->right;
  return os;
}

std::ostream& operator<<(std::ostream& os, const Logical& expr) {
  os << expr.left << " " << expr.op << " " << expr.right;
  return os;
}
