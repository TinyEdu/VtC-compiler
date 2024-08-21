// Unary.h

#ifndef UNARY_H
#define UNARY_H

#include "Expression.h"

class Unary : public Expression {
 public:
  Unary(Token op, Expression* right);
  std::any accept(Visitor* visitor) override;

  Token op;
  Expression* right;

  friend std::ostream& operator<<(std::ostream& os, const Unary* expr);
  friend std::ostream& operator<<(std::ostream& os, const Unary& expr);
};

#endif  // UNARY_H