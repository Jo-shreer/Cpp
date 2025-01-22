/*
How to Compile and Run:
Install Google Test (if you haven't already). You can download it from the Google Test GitHub repository.

Compile your code with the following command (assuming GTest is installed):
bash
g++ -std=c++11 -lgtest -lgtest_main -pthread your_test_file.cpp -o your_test_program

Run the compiled test program:
./your_test_program

Expected Output:

[ RUN      ] AdditionTest.PositiveNumbers
[       OK ] AdditionTest.PositiveNumbers (0 ms)
[ RUN      ] AdditionTest.NegativeNumbers
[       OK ] AdditionTest.NegativeNumbers (0 ms)
[ RUN      ] AdditionTest.Zero
[       OK ] AdditionTest.Zero (0 ms)
[----------] 3 tests from 1 test suite ran. (0 ms total)

[  PASSED  ] 3 tests.
Summary:
This simple example demonstrates how to write a basic unit test using Google Test in C++. It tests the correctness of an Add function by verifying that it correctly handles positive numbers, negative numbers, and zero.

    */

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
