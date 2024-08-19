// Assign.h

#ifndef ASSIGN_H
#define ASSIGN_H

#include "Expression.h"

class Assign : public Expression {
 public:
  Assign(Token name, Expression* value);
  std::any accept(Visitor* visitor) override;

  Token name;
  Expression* value;

  friend std::ostream& operator<<(std::ostream& os, const Unary* expr);
};

#endif  // ASSIGN_H