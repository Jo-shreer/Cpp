/*
You can mark functions or types with [[nodiscard]] to warn 
if the result is ignored.

Before 
There was no standard way to warn if a function's return value was ignored.
Example: 
you might call a function that returns an error code 
but forget to check it, causing bugs.

Why useful?
Helps catch mistakes early by making you handle important return values.
Especially useful for error codes, resource handles, etc.

*/

#include <iostream>

[[nodiscard]] int compute() 
{
    return 42;
}

int main() 
{
    int x = compute();  // OK, result used
    std::cout << "Result: " << x << "\n";

    // Uncommenting below line will generate a compiler warning:
    // compute();

    return 0;
}
