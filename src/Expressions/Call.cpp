#include "Call.h"

#include "Visitor.h"

Call::Call(Expression* callee, Token paren, std::vector<Expression*> arguments)
    : callee(callee), paren(paren), arguments(arguments) {}

std::any Call::accept(Visitor* visitor) { return visitor->visit(this); }

std::ostream& operator<<(std::ostream& os, const Call& expr) {
  os << "Call: " << expr.callee << " " << expr.paren;
  return os;
}

std::ostream& operator<<(std::ostream& os, const Call* expr) {
  os << "Call: " << expr->callee << " " << expr->paren;
  return os;
}

