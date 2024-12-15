#include "Binary.h"

#include "Visitor/Visitor.h"

Binary::Binary(Expression* left, Token op, Expression* right)
    : left(left), op(op), right(right) {}

std::any Binary::accept(Visitor* visitor) {
  return visitor->visit(this);
}

std::ostream& operator<<(std::ostream& os, const Binary* expr) {
  os << expr->left << " " << expr->op << " " << expr->right;
  return os;
}

std::ostream& operator<<(std::ostream& os, const Binary& expr) {
  os << expr.left << " " << expr.op << " " << expr.right;
  return os;
}