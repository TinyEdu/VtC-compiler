#ifndef NOTFOUNDINSCOPEEXCEPTION_H
#define NOTFOUNDINSCOPEEXCEPTION_H

#include <stdexcept>

class NotFoundInScopeException final : public std::runtime_error
{
public:
    using runtime_error::runtime_error;
};

#endif //NOTFOUNDINSCOPEEXCEPTION_H
