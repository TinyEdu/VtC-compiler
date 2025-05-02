#ifndef ARITY_MISMATCH_EXCEPTION_H
#define ARITY_MISMATCH_EXCEPTION_H

#include <stdexcept>
#include <string>

class ArityMismatchException final : public std::runtime_error
{
public:
    explicit ArityMismatchException(const std::string& message);
};

#endif // ARITY_MISMATCH_EXCEPTION_H
