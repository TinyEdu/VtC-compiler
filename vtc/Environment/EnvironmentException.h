#ifndef ENVIRONMENTEXCEPTION_H
#define ENVIRONMENTEXCEPTION_H

#include <stdexcept>

class EnvironmentException final : public std::runtime_error
{
public:
    using runtime_error::runtime_error;
};

#endif //ENVIRONMENTEXCEPTION_H
