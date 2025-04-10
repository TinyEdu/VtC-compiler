#ifndef REACHEDEND_H
#define REACHEDEND_H

#include <stdexcept>

class ReachedEnd final : public std::runtime_error
{
public:
    using runtime_error::runtime_error;
};

#endif //REACHEDEND_H
