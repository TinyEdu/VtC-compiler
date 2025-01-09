#include "Return.h"

Return::Return(std::any value): value(std::move(value))
{
}

const char* Return::what() const noexcept
{
    return "Class `Return` exception thrown";
}
