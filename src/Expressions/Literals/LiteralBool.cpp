#include "LiteralBool.h"

#include "LiteralInt.h"
#include "LiteralFloat.h"
#include "LiteralString.h"
#include "LiteralDouble.h"
#include "OperationsDispatcher.h"
#include "Visitor.h"


std::any LiteralBool::accept(Visitor* visitor) {
  return visitor->visit(this);
}

Expression* LiteralBool::process(LiteralInt* expr, Token token) {
  return OperationsDispatcher::dispatch(expr, this, token);
};

Expression* LiteralBool::process(LiteralFloat* expr, Token token) {
  return OperationsDispatcher::dispatch(expr, this, token);
};

Expression* LiteralBool::process(LiteralString* expr, Token token) {
  return OperationsDispatcher::dispatch(expr, this, token);
};

Expression* LiteralBool::process(LiteralBool* expr, Token token) {
  return OperationsDispatcher::dispatch(expr, this, token);
};

Expression* LiteralBool::process(LiteralDouble* expr, Token token) {
  return OperationsDispatcher::dispatch(expr, this, token);
};

Expression* LiteralBool::process(Token token) {
  return OperationsDispatcher::dispatch(this, token);
}