#include "ClockCallable.h"

#include <chrono>
#include "LogManager/LogManager.h"
#include "Expressions/ExpressionsWorld.h"


ClockCallable::ClockCallable() = default;
ClockCallable::~ClockCallable() = default;

int ClockCallable::arity()
{
    return 0;
}

std::any ClockCallable::call(Interpreter* interpreter, std::span<Expression* const> arguments)
{
    LogManager::log() << "ClockCallable::call\n";
    const auto result = static_cast<int>(std::chrono::duration_cast<std::chrono::milliseconds>(
        std::chrono::system_clock::now().time_since_epoch()).count());

// ??? @TODO    return static_cast<Expression*>(new LiteralInt(result));
    return new LiteralInt(result);
}
