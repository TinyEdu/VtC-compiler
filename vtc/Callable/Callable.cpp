#include "Callable.h"

Callable::Callable() = default;
Callable::~Callable() = default;

std::ostream& operator<<(std::ostream& os, [[maybe_unused]] const Callable& expr)
{
    os << "Callable";
    return os;
}

std::ostream& operator<<(std::ostream& os, [[maybe_unused]] const Callable* expr)
{
    os << "Callable";
    return os;
}
