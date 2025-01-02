#include <iostream>

int main() {
    auto x = 5;             // x is deduced as int
    auto y = 3.14;          // y is deduced as double
    auto z = "Hello";       // z is deduced as const char*

    std::cout << x << " " << y << " " << z << std::endl; // Output: 5 3.14 Hello
    return 0;
}
