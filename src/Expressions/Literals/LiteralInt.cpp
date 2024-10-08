#include "LiteralInt.h"

#include "LiteralBool.h"
#include "LiteralDouble.h"
#include "LiteralFloat.h"
#include "LiteralString.h"
#include "OperationsDispatcher.h"

#include "Visitor.h"

std::any LiteralInt::accept(Visitor* visitor) {
  return visitor->visit(this);
}

Expression* LiteralInt::process(LiteralInt* expr, Token token) {
  return OperationsDispatcher::dispatch(expr, this, token);
};

Expression* LiteralInt::process(LiteralFloat* expr, Token token) {
  return OperationsDispatcher::dispatch(expr, this, token);
};

Expression* LiteralInt::process(LiteralString* expr, Token token) {
  return OperationsDispatcher::dispatch(expr, this, token);
};

Expression* LiteralInt::process(LiteralBool* expr, Token token) {
  return OperationsDispatcher::dispatch(expr, this, token);
};

Expression* LiteralInt::process(LiteralDouble* expr, Token token) {
  return OperationsDispatcher::dispatch(expr, this, token);
};

Expression* LiteralInt::process(Token token) {
  return OperationsDispatcher::dispatch(this, token);
}