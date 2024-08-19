// Literal.h

#ifndef LITERAL_H
#define LITERAL_H

#include "Expression.h"
#include "OperationsDispatcher.h"

// forward declarations
class LiteralInt;
class LiteralFloat;
class LiteralString;
class LiteralBool;

class LiteralDouble;
// class LiteralArray; // @TODO - implement arrays and chars
// class LiteralChar;

class Literal : public Expression {
 public:
  Literal() = default;
  virtual ~Literal() = default;

  // Note: Literal does not ha ve a visitor function, it just passes rhis requirement to its subclasses
  virtual std::any accept(Visitor* visitor) = 0;

  // [___] value;

  // declare double dispatch visiting functions
  // expr = left, this = right
  virtual Expression* process(Literal* expr, Token token) = 0;
  virtual Expression* process(LiteralInt* expr, Token token) = 0;
  virtual Expression* process(LiteralFloat* expr, Token token) = 0;
  virtual Expression* process(LiteralString* expr, Token token) = 0;
  virtual Expression* process(LiteralBool* expr, Token token) = 0;
  virtual Expression* process(LiteralDouble* expr, Token token) = 0;

  friend std::ostream& operator<<(std::ostream& os, const Literal* expr);
};

#endif  // LITERAL_H