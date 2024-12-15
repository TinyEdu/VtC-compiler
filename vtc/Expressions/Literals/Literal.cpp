#include "Literal.h"

#include "Visitor/Visitor.h"

std::any Literal::accept(Visitor* visitor) {
  return visitor->visit(this);
}