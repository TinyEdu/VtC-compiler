#include "gtest/gtest.h"
#include "LogManager/LogManager.h"

TEST(LoggingValidation, IsLoggingWorkingCorrectly) {
  LogManager::log("NORMAL !!!!! hello world");
  LogManager::warn("WARNING !!!! hello world");
  LogManager::crit("CRITICAL !!! hello world");

  EXPECT_EQ(1, 1);
}

void testMe()
{
  LogManager::log("Calling from inside of testMe method");
}

TEST(LoggingValidation, IsLoggingGettingTheCorrectMethod) {
  LogManager::log("Calling from inside of test");

  testMe();
}