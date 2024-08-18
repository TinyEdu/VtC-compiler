// Grouping.h

#ifndef GROUPING_H
#define GROUPING_H

#include "Expression.h"


class Grouping : public Expression {
 public:
  Grouping(Expression* expression);
  std::any accept(Visitor* visitor) override;

  Expression* expression;

  friend std::ostream& operator<<(std::ostream& os, const Grouping* expr);
};


#endif // GROUPING_H