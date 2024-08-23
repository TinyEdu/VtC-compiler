#include "LiteralDouble.h"

#include "LiteralInt.h"
#include "LiteralFloat.h"
#include "LiteralString.h"
#include "LiteralBool.h"
#include "OperationsDispatcher.h"
#include "Visitor.h"

std::any LiteralDouble::accept(Visitor* visitor) {
  return visitor->visit(this);
}


Expression* LiteralDouble::process(LiteralInt* expr, Token token) {
  return OperationsDispatcher::dispatch(expr, this, token);
};

Expression* LiteralDouble::process(LiteralFloat* expr, Token token) {
  return OperationsDispatcher::dispatch(expr, this, token);
};

Expression* LiteralDouble::process(LiteralString* expr, Token token) {
  return OperationsDispatcher::dispatch(expr, this, token);
};

Expression* LiteralDouble::process(LiteralBool* expr, Token token) {
  return OperationsDispatcher::dispatch(expr, this, token);
};

Expression* LiteralDouble::process(LiteralDouble* expr, Token token) {
  return OperationsDispatcher::dispatch(expr, this, token);
};

Expression* LiteralDouble::process(Token token) {
  return OperationsDispatcher::dispatch(this, token);
}