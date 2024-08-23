// LiteralDouble.h

#ifndef LiteralDouble_H
#define LiteralDouble_H

#include "string.h"
#include "Literal.h"

class Expression;
class LiteralInt;
class LiteralFloat;
class LiteralString;
class LiteralBool;

class LiteralDouble : public Literal {
public:
LiteralDouble(double value) : value(value) {};

double value;

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


friend std::ostream& operator<<(std::ostream& os, const LiteralDouble* expr) {
  os << expr->value;
  return os;
};

friend std::ostream& operator<<(std::ostream& os, const LiteralDouble& expr) {
  os << expr.value;
  return os;
};

};
#endif  // LiteralDouble_H
