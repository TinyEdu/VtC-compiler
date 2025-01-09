#include "NonBooleanConditionException.h"

NonBooleanConditionException::NonBooleanConditionException(const std::string& message): std::runtime_error(message)
{

}
