#include "gtest/gtest.h"
#include "../E2E/tools/E2ETester.h"

TEST(E2E, IsTestingToolWorkingCorrectly)
{
    const bool result = E2ETester::runTest("this path does not exist", "this path does not exist");

    ASSERT_FALSE(result);
}

TEST(E2E, VariableAssignment)
{
    const std::string input_path = R"(01\input_test.nk)";
    const std::string expected_output_path = R"(01\expected_output.nk)";

    const bool result = E2ETester::runTest(input_path, expected_output_path);

    ASSERT_TRUE(result);
}

TEST(E2E, BasicArithmeticOperations)
{
    const std::string input_path = R"(02\input_test.nk)";
    const std::string expected_output_path = R"(02\expected_output.nk)";

    const bool result = E2ETester::runTest(input_path, expected_output_path);

    ASSERT_TRUE(result);
}

TEST(E2E, LogicalOperations)
{
    const std::string input_path = R"(03\input_test.nk)";
    const std::string expected_output_path = R"(03\expected_output.nk)";

    const bool result = E2ETester::runTest(input_path, expected_output_path);

    ASSERT_TRUE(result);
}

TEST(E2E, VariableScopes)
{
    const std::string input_path = R"(04\input_test.nk)";
    const std::string expected_output_path = R"(04\expected_output.nk)";

    const bool result = E2ETester::runTest(input_path, expected_output_path);

    ASSERT_TRUE(result);
}

TEST(E2E, ConditionalStatements)
{
    const std::string input_path = R"(05\input_test.nk)";
    const std::string expected_output_path = R"(05\expected_output.nk)";

    const bool result = E2ETester::runTest(input_path, expected_output_path);

    ASSERT_TRUE(result);
}

TEST(E2E, ForLoop)
{
    const std::string input_path = R"(06\input_test.nk)";
    const std::string expected_output_path = R"(06\expected_output.nk)";

    const bool result = E2ETester::runTest(input_path, expected_output_path);

    ASSERT_TRUE(result);
}

TEST(E2E, WhileLoop)
{
    const std::string input_path = R"(07\input_test.nk)";
    const std::string expected_output_path = R"(07\expected_output.nk)";

    const bool result = E2ETester::runTest(input_path, expected_output_path);

    ASSERT_TRUE(result);
}

TEST(E2E, FunctionDeclarationAndCall)
{
    const std::string input_path = R"(08\input_test.nk)";
    const std::string expected_output_path = R"(08\expected_output.nk)";

    const bool result = E2ETester::runTest(input_path, expected_output_path);

    ASSERT_TRUE(result);
}

TEST(E2E, RecursiveFunction)
{
    const std::string input_path = R"(09\input_test.nk)";
    const std::string expected_output_path = R"(09\expected_output.nk)";

    const bool result = E2ETester::runTest(input_path, expected_output_path);

    ASSERT_TRUE(result);
}

TEST(E2E, ShadowingVariables)
{
    const std::string input_path = R"(10\input_test.nk)";
    const std::string expected_output_path = R"(10\expected_output.nk)";

    const bool result = E2ETester::runTest(input_path, expected_output_path);

    ASSERT_TRUE(result);
}
