#include "LiteralFloat.h"

#include "LiteralBool.h"
#include "LiteralDouble.h"
#include "LiteralInt.h"
#include "LiteralString.h"
#include "OperationsDispatcher.h"
#include "Visitor.h"

std::any LiteralFloat::accept(Visitor* visitor) {
  return visitor->visit(this);
}

Expression* LiteralFloat::process(LiteralInt* expr, Token token) {
  return OperationsDispatcher::dispatch(expr, this, token);
};

Expression* LiteralFloat::process(LiteralFloat* expr, Token token) {
  return OperationsDispatcher::dispatch(expr, this, token);
};

Expression* LiteralFloat::process(LiteralString* expr, Token token) {
  return OperationsDispatcher::dispatch(expr, this, token);
};

Expression* LiteralFloat::process(LiteralBool* expr, Token token) {
  return OperationsDispatcher::dispatch(expr, this, token);
};

Expression* LiteralFloat::process(LiteralDouble* expr, Token token) {
  return OperationsDispatcher::dispatch(expr, this, token);
};

Expression* LiteralFloat::process(Token token) {
  return OperationsDispatcher::dispatch(this, token);
}