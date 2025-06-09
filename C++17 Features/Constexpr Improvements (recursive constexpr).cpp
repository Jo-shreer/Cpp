/*

You can write recursive constexpr functions.

Earlier - 
constexpr functions were very limited (no loops or recursion).

Now
1. Enables complex compile-time computations
2. More powerful metaprogramming

*/
#include <iostream>

constexpr int factorial(int n) 
{
    return n <= 1 ? 1 : n * factorial(n - 1);
}

int main() {
    constexpr int f = factorial(5);
    std::cout << "factorial(5) = " << f << std::endl;
    return 0;
}
