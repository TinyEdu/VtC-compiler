// ErrorHandler.h

#ifndef ERROR_HANDLER_H
#include <iostream>
#include <string>

#include "LogManager.h"

class ErrorHandler {
 public:
  ErrorHandler();
  ~ErrorHandler();

  static void error(int line, const std::string& message);
  static void report(int line, const std::string& where,
                     const std::string& message);

  bool hadError();
  bool hadRuntimeError();
};

#endif  // ERROR_HANDLER_H