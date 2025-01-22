#include <gtest/gtest.h>

// Function to test
int Add(int a, int b) {
    return a + b;
}

// Test case for the Add function
TEST(AdditionTest, PositiveNumbers) {
    EXPECT_EQ(Add(1, 2), 3);  // Check if 1 + 2 equals 3
}

TEST(AdditionTest, NegativeNumbers) {
    EXPECT_EQ(Add(-1, -2), -3);  // Check if -1 + -2 equals -3
}

TEST(AdditionTest, Zero) {
    EXPECT_EQ(Add(0, 0), 0);  // Check if 0 + 0 equals 0
}

// Main function to run all the tests
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);  // Initialize Google Test
    return RUN_ALL_TESTS();  // Run all tests
}
