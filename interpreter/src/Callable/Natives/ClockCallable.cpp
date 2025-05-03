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

std::shared_ptr<Expression> ClockCallable::call(Interpreter& interpreter,
                                                std::span<std::shared_ptr<Expression> const> arguments)
{
    LogManager::LOG() << "ClockCallable::call\n";
    const auto result = static_cast<int>(std::chrono::duration_cast<std::chrono::milliseconds>(
        std::chrono::system_clock::now().time_since_epoch()).count());

    return std::make_shared<LiteralInt>(result);
}
