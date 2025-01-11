#include <bits/fs_fwd.h>
#include <bits/fs_path.h>

#include "gtest/gtest.h"
#include "../E2E/tools/E2ETester.h"

TEST(E2E, IsTestingToolWorkingCorrectly)
{
    const bool result = E2ETester::runTest("this path does not exist", "this path does not exist");

    ASSERT_FALSE(result);
}

TEST(E2E, 01)
{
    const std::string input_path = R"(01\input_test.nk)";
    const std::string expected_output_path = R"(01\expected_output.nk)";

    const bool result = E2ETester::runTest(input_path, expected_output_path);

    ASSERT_TRUE(result);
}

TEST(E2E, 02)
{
    const std::string input_path = R"(02\input_test.nk)";
    const std::string expected_output_path = R"(02\expected_output.nk)";

    const bool result = E2ETester::runTest(input_path, expected_output_path);

    ASSERT_TRUE(result);
}
