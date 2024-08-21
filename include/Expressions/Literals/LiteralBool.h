// LiteralBool.h

#ifndef LITERAL_BOOL_H
#define LITERAL_BOOL_H

#include "Literal.h"
#include "OperationsDispatcher.h"

class LiteralBool : public Literal {
 public:
  LiteralBool(bool value) { this->value = value; };

  bool value;

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

  friend std::ostream& operator<<(std::ostream& os, const LiteralBool* expr);
};

#endif  // LITERAL_BOOL_H