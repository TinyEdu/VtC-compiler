#include "LogManager.h"

#include "ClockCallable.h"

int ClockCallable::arity() {
  return 0;
}

std::any ClockCallable::call(Interpreter* interpreter, std::vector<Expression*> arguments) {
  LOG << "ClockCallable::call" << ENDL;  
  return int(std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count());
}

// print overloading


