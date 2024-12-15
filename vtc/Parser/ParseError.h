#ifndef PARSEERROR_H
#define PARSEERROR_H

#include <stdexcept>

class ParseError final : public std::runtime_error {
public:
    using runtime_error::runtime_error;
};

#endif //PARSEERROR_H
