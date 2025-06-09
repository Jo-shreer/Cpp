/*
You can define static variables as inline inside the class.

Before - Static variables needed separate definitions in .cpp files:

struct Foo 
{
    static int counter;   // declaration
};
int Foo::counter = 0;     // definition outside class

1. Simplifies header-only libraries and templates
2. Avoids linker errors from multiple definitions

*/

#include <iostream>
struct Foo 
{
    static inline int counter = 42;
};

int main() 
{
    std::cout << "Foo::counter = " << Foo::counter << std::endl;
    return 0;
}
