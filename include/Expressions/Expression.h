// Expression.h

#ifndef EXPRESSION_H
#define EXPRESSION_H

#include <any>
#include <string>

#include "LogManager.h"
#include "Token.h"

// forward declarations
class Assign;
class Binary;
class Grouping;
class Literal;
class Unary;
class Logical;
class Variable;

class Visitor;

class Expression {
 public:
  Expression() = default;
  virtual ~Expression() = default;
  virtual std::any accept(Visitor* visitor) = 0;
};

#endif  // EXPRESSION_H