#include "Callable.h"


std::ostream& operator<<(std::ostream& os, const Callable& expr) {
  os << "Callable";
  return os;
}

std::ostream& operator<<(std::ostream& os, const Callable* expr) {
  os << "Callable";
  return os;
}