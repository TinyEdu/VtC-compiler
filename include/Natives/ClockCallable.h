// ClockFunction.h

#ifndef CLOCKFUNCTION_H

#define CLOCKFUNCTION_H
#include "Callable.h"
#include <chrono>

class ClockCallable : public Callable {
 public:
  ClockCallable() {};
  ~ClockCallable() {};

  int arity() override;
  std::any call(Interpreter* interpreter, std::vector<Expression*> arguments) override;
};

#endif  // CLOCKFUNCTION_H