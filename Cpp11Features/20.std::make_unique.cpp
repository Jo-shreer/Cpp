/*
What does std::make_unique do?
Introduced in C++14, std::make_unique is a factory function 
that creates a std::unique_ptr for you, 
forwarding the constructor arguments, like:
auto p = std::make_unique<int>(10);

Before C++14 (and C++17):
You had to create std::unique_ptr like this:
std::unique_ptr<int> p(new int(10));

This syntax is:
1. Verbose
2. Error-prone (if you forget new, or if an exception is thrown
between new and assignment)
3. Harder to read

Why is it better?
Safer: avoids potential memory leaks if exceptions occur
Cleaner and more readable
Automatically deduces the type, so no need to write it twice
Recommended modern way to create unique_ptr

*/

#include <iostream>
#include <memory>

struct Foo 
{
    int x;
    Foo(int val) : x(val) 
    {
        std::cout << "Foo constructed with x = " << x << "\n";
    }
};

int main() 
{
    // Old way (pre-C++14)
    std::unique_ptr<Foo> p1(new Foo(42));

    // New way (C++14 and later)
    auto p2 = std::make_unique<Foo>(100);

    std::cout << "p1->x = " << p1->x << "\n";
    std::cout << "p2->x = " << p2->x << "\n";

    return 0;
}

Foo constructed with x = 42
Foo constructed with x = 100
p1->x = 42
p2->x = 100
  

