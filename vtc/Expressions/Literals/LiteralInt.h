// LiteralInt.h

#ifndef LiteralInt_H
#define LiteralInt_H

#include "Expressions/Literals/Literal.h"

class Expression;
class LiteralFloat;
class LiteralString;
class LiteralBool;
class LiteralDouble;

class LiteralInt : public Literal {
 public:
  LiteralInt(int value) : value(value){};

  int value;

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

  friend std::ostream& operator<<(std::ostream& os, const LiteralInt* expr) {
    os << expr->value;
    return os;
  };

  friend std::ostream& operator<<(std::ostream& os, const LiteralInt& expr) {
    os << expr.value;
    return os;
  };
};
#endif  // LiteralInt_H
