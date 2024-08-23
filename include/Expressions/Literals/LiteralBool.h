// LiteralBool.h

#ifndef LiteralBool_H
#define LiteralBool_H

#include "Literal.h"
#include "string.h"

class Expression;
class LiteralInt;
class LiteralFloat;
class LiteralString;
class LiteralDouble;

class LiteralBool : public Literal {
 public:
  LiteralBool(bool value) : value(value){};

  bool value;

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

  friend std::ostream& operator<<(std::ostream& os, const LiteralBool* expr) {
    os << expr->value;
    return os;
  };

  friend std::ostream& operator<<(std::ostream& os, const LiteralBool& expr) {
    os << expr.value;
    return os;
  };
};
#endif  // LiteralBool_H
