#include "ArityMismatchException.h"

ArityMismatchException::ArityMismatchException(const std::string& message): std::runtime_error(message)
{
}
