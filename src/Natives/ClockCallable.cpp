#include "LogManager.h"
#include "ExpressionWorld.h"

#include "ClockCallable.h"

int ClockCallable::arity() {
  return 0;
}

std::any ClockCallable::call(Interpreter* interpreter, std::vector<Expression*> arguments) {
  LOG << "ClockCallable::call" << ENDL;  
  int result = int(std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count());
  return static_cast<Expression*>(new LiteralInt(result));
}
