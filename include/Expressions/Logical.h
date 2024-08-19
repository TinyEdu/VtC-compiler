// Logical.h

#ifndef LOGICAL_H
#define LOGICAL_H

#include "Expression.h"

class Logical : public Expression {
 public:
  Logical(Expression* left, Token op, Expression* right);
  std::any accept(Visitor* visitor) override;

  Expression* left;
  Token op;
  Expression* right;

  friend std::ostream& operator<<(std::ostream& os, const Unary* expr);
};

#endif  // LOGICAL_H