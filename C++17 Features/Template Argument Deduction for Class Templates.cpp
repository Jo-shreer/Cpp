/*
Class templates support argument deduction:

Before - You had to specify template parameters explicitly for classes:
std::pair<int, double> p(1, 3.14);

Now
Less verbose and easier to read
Similar to function template argument deduction

*/

#include <iostream>
#include <utility>

int main() 
{
    std::pair p(1, 3.14);
    std::cout << "Pair: " << p.first << ", " << p.second << std::endl;
    return 0;
}

op

Pair: 1, 3.14
