#include <iostream>

constexpr int value = 10;

// This will pass because the condition is true
static_assert(value > 0, "Value must be greater than zero");

// Uncommenting the following line would cause a compile-time error
static_assert(value > 15, "Value must be greater than zero"); // error static_assert(value > 15, "Value must be greater than zero");

int main() {
    std::cout << "Value is: " << value << std::endl;
    return 0;
}
