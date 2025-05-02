#ifndef MISSING_INITIALIZER_EXCEPTION_H
#define MISSING_INITIALIZER_EXCEPTION_H

#include <stdexcept>

class MissingInitializerException final : public std::runtime_error
{
public:
    using runtime_error::runtime_error;
};

#endif // MISSING_INITIALIZER_EXCEPTION_H
