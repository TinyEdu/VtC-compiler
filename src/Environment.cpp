#include "Environment.h"

Environment::Environment()
{
}

Environment::~Environment()
{
}

void Environment::define(std::string name, Expression* value)
{
    env[name] = value;
}

Expression* Environment::lookup(std::string name)
{
    // check if the variable is defined
    if (env.find(name) == env.end())
    {
        throw std::runtime_error("Undefined variable '" + name + "'");
        // if not, return nullptr
        return nullptr;
    }

    // if exists -> return the value of the variable
    return env[name];
}