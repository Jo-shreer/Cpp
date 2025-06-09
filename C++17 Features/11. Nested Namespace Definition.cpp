/*
Nested Namespace definition - You can write them all at once:

Before C++17:
You had to write nested namespaces with multiple blocks:
namespace A {
    namespace B {
        namespace C {
            // code
        }
    }
}

Why useful?
Saves lines and indentation.
Improves readability.

*/

#include <iostream>

namespace A::B::C 
{
    void foo() 
{
        std::cout << "Hello from nested namespace!\n";
    }
}

int main() {
    A::B::C::foo();
    return 0;
}

Output:
Hello from nested namespace!
