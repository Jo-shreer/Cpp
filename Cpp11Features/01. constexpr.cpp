/*A function that is marked constexpr is evaluated at compile time 
if its arguments are constant expressions. 
A constexpr function must have a body, and its return value 
must be determinable at compile time.

*Benefits
1. Compile-Time Computation
The most significant advantage of constexpr is that it allows computations
to be performed at compile time, rather than at runtime. 
This can result in major performance improvements,especially for 
computations that would otherwise have to be repeated every time the
program runs.
2. Faster Execution
By using constexpr, you can avoid redundant runtime calculations, 
leading to faster execution. 
If a value is computed during program startup (or even before), you don’t need to recompute it each time it is used.

*Limitations of constexpr Functions:
Complexity: A constexpr function cannot contain code that cannot be 
evaluated at compile time, such as:
Loops with non-constant bounds
Dynamic memory allocation
Use of non-constant variables
Runtime operations like std::cin or std::cout
Constant Expressions: Only constant expressions (like literal constants, constexpr variables, etc.) can be passed to a constexpr function 
for it to be evaluated at compile time.
*/

#include <iostream>
constexpr int getSquare(int x)    //constexpr function
{  
    return x * x;                 // This will be evaluated at compile time
}

int main() {
    constexpr int squareOfFive = getSquare(5); // Evaluated at compile time
    std::cout << "Square of 5 is: " << squareOfFive << std::endl;
    return 0;
}
