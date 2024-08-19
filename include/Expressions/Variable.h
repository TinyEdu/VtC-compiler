// Variable.h

#ifndef VARIABLE_H
#define VARIABLE_H

#include "Expression.h"

class Variable : public Expression {
 public:
  Variable(Token name);
  std::any accept(Visitor* visitor) override;

  Token name;

  friend std::ostream& operator<<(std::ostream& os, const Variable* expr);
};

#endif  // VARIABLE_H