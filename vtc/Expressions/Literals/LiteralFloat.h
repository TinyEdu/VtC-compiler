// LiteralFloat.h

#ifndef LiteralFloat_H
#define LiteralFloat_H

#include "Expressions/Literals/Literal.h"

class Expression;
class LiteralInt;
class LiteralString;
class LiteralBool;
class LiteralDouble;

class LiteralFloat : public Literal {
 public:
  LiteralFloat(float value) : value(value){};

  float value;

  virtual std::any accept(Visitor* visitor);

  virtual Expression* process(Literal* expr, Token token) override {
    return expr->process(this, token);
  };

  virtual Expression* process(LiteralInt* expr, Token token);
  virtual Expression* process(LiteralFloat* expr, Token token);
  virtual Expression* process(LiteralString* expr, Token token);
  virtual Expression* process(LiteralBool* expr, Token token);
  virtual Expression* process(LiteralDouble* expr, Token token);
  virtual Expression* process(Token token);

  friend std::ostream& operator<<(std::ostream& os, const LiteralFloat* expr) {
    os << expr->value;
    return os;
  };

  friend std::ostream& operator<<(std::ostream& os, const LiteralFloat& expr) {
    os << expr.value;
    return os;
  };
};
#endif  // LiteralFloat_H
