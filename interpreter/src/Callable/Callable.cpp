#include "Callable.h"

#include <iostream>

Callable::Callable() = default;
Callable::~Callable() = default;

std::ostream& operator<<(std::ostream& os, [[maybe_unused]] const Callable& expr)
{
    std::cout << "Callable";
    return os;
}

std::ostream& operator<<(std::ostream& os, [[maybe_unused]] const Callable* expr)
{
    std::cout << "Callable";
    return os;
}
