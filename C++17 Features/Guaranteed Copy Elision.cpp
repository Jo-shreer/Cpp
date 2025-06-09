/*
In some situations (like returning a local object),
copy elision is guaranteed, and no copy/move constructor is called.

Before C++17:
Copy elision (omitting copy/move constructor calls) was optional, 
compiler-dependent.
Code like return obj; might call copy/move constructors or not.

Why useful?
More predictable performance.
Avoids unnecessary overhead.
Makes code easier to reason about.
*/

#include <iostream>

struct Obj 
{
    Obj() { std::cout << "Constructed\n"; }
    Obj(const Obj&) { std::cout << "Copied\n"; }
    Obj(Obj&&) { std::cout << "Moved\n"; }
};

Obj create() 
{
    return Obj();
}

int main() 
{
    Obj o = create(); // Guaranteed no copy/move in C++17
    return 0;
}

Output:
Constructed
(No "Copied" or "Moved" lines, guaranteed by C++17)
