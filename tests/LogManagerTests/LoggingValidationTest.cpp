#include "gtest/gtest.h"
#include "LogManager/LogManager.h"

TEST(LoggingValidation, IsLoggingWorkingCorrectly)
{
    LogManager::log() << "Hello, " << "world!";
    LogManager::warn() << "Hello, " << "world!";
    LogManager::crit() << "Hello, " << "world!";
}

void testMe()
{
    LogManager::log() << "Calling from inside of testMe method";
}

TEST(LoggingValidation, IsLoggingGettingTheCorrectMethod)
{
    LogManager::log() << "Calling from inside of test";

    testMe();
}
