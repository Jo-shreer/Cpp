/*
C++17:
Aggregate initialization includes base classes, 
allowing direct initialization of bases.

Before C++17:
Aggregate initialization (brace initialization without constructors) 
did not include base class members.
So you couldn’t initialize base class parts using braces.

Why useful?
Makes initialization of derived aggregates easier and cleaner.
No need for custom constructors for simple cases.

*/

#include <iostream>

struct Base 
{
    int x;
};

struct Derived : Base 
{
    int y;
};

int main() 
{
    Derived d{1, 2}; // Initializes Base::x = 1, Derived::y = 2
    std::cout << "Derived.x = " << d.x << ", Derived.y = " << d.y << "\n";
    return 0;
}

Output:
Derived.x = 1, Derived.y = 2


