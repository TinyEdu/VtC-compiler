#include "gtest/gtest.h"
#include "../E2E/tools/E2ETester.h"


TEST(ScannerValidation, ptx)
{
    const std::string input_path = "C:/Users/nikod/Documents/GitHub/VtC-compiler/tests/InterpreterTests/expected_simple_test.st";
    const std::string expected_output_path = "C:/Users/nikod/Documents/GitHub/VtC-compiler/tests/InterpreterTests/expected_simple_test.st";

    E2ETester::runTest(input_path, expected_output_path);
}