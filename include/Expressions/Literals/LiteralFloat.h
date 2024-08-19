// LiteralFloat.h

#ifndef LITERAL_FLOAT_H
#define LITERAL_FLOAT_H

#include "Literal.h"

class LiteralFloat : public Literal {
 public:
  LiteralFloat(float value);

  float value;

  virtual Expression* process(Literal* expr, Token token) override {
    return expr->process(this, token);
  };

  virtual Expression* process(LiteralInt* expr, Token token) override {
    return OperationsDispatcher::dispatch(expr, this, token);
  };
  virtual Expression* process(LiteralFloat* expr, Token token) override {
    return OperationsDispatcher::dispatch(expr, this, token);
  };
  virtual Expression* process(LiteralString* expr, Token token) override {
    return OperationsDispatcher::dispatch(expr, this, token);
  };
  virtual Expression* process(LiteralBool* expr, Token token) override {
    return OperationsDispatcher::dispatch(expr, this, token);
  };
  virtual Expression* process(LiteralDouble* expr, Token token) override {
    return OperationsDispatcher::dispatch(expr, this, token);
  };

  friend std::ostream& operator<<(std::ostream& os, const LiteralFloat* expr);
};

#endif  // LITERAL_FLOAT_H