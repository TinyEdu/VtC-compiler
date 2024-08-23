#include "LiteralString.h"

#include "LiteralInt.h"
#include "LiteralFloat.h"
#include "LiteralBool.h"
#include "LiteralDouble.h"
#include "OperationsDispatcher.h"

#include "Visitor.h"

std::any LiteralString::accept(Visitor* visitor) {
  return visitor->visit(this);
}


Expression* LiteralString::process(LiteralInt* expr, Token token) {
  return OperationsDispatcher::dispatch(expr, this, token);
};

Expression* LiteralString::process(LiteralFloat* expr, Token token) {
  return OperationsDispatcher::dispatch(expr, this, token);
};

Expression* LiteralString::process(LiteralString* expr, Token token) {
  return OperationsDispatcher::dispatch(expr, this, token);
};

Expression* LiteralString::process(LiteralBool* expr, Token token) {
  return OperationsDispatcher::dispatch(expr, this, token);
};

Expression* LiteralString::process(LiteralDouble* expr, Token token) {
  return OperationsDispatcher::dispatch(expr, this, token);
};

Expression* LiteralString::process(Token token) {
  return OperationsDispatcher::dispatch(this, token);
}