// Return.h

#ifndef RETURN_H
#define RETURN_H

#include <stdexcept>

class Return : public std::runtime_error {
public:
    const void* value;

    Return(const void* value)
        : std::runtime_error(""), value(value) {}
};


#endif  // RETURN_H