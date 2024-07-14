#include "gtest/gtest.h"
#include "Calculator.h"

// Test case for the add function
TEST(MathUtilsTest, AddFunction_EXPECTED_SUCCESS) {
    // Test positive numbers
    EXPECT_EQ(Calculator::add(1, 2), 3);
}

TEST(MathUtilsTest, AddFunction_EXPECTED_FAIL) {
    // This should fail
    EXPECT_EQ(Calculator::add(1, 2), 100);
}


// Additional tests can be added here

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
