#ifndef NON_BOOLEAN_CONDITION_EXCEPTION_H
#define NON_BOOLEAN_CONDITION_EXCEPTION_H

#include <stdexcept>
#include <string>

class NonBooleanConditionException final : public std::runtime_error
{
public:
    explicit NonBooleanConditionException(const std::string& message);
};

#endif // NON_BOOLEAN_CONDITION_EXCEPTION_H
