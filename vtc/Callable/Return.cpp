#include "Return.h"

Return::Return(std::shared_ptr<Literal> value) : value(std::move(value))
{
}

const char* Return::what() const noexcept
{
    return "Class `Return` exception thrown";
}
