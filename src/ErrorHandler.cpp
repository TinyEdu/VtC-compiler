#include "ErrorHandler.h"

ErrorHandler::ErrorHandler() {}

ErrorHandler::~ErrorHandler() {}

void ErrorHandler::error(int line, const std::string& message) {
  report(line, "", message);
}

void ErrorHandler::report(int line, const std::string& where,
                          const std::string& message) {
  LOG << "[line " << line << "] Error" << where << ": " << message << "\n";
}

bool ErrorHandler::hadError() {
  return true;
}

bool ErrorHandler::hadRuntimeError() {
  return true;
}
