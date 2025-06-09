/*
Function overloading means you can have multiple functions with the same name
but with different parameters.
The compiler chooses the correct function based on:
Number of parameters
Types of parameters

Different return type only	    ❌ Not overloading 
Different scopes (name hiding)	❌ Not overloading 
Different const on return type	❌ Not overloading 
Different exception specifiers	❌ Not overloading 
Template specialization	        ❌ Not counted as overload in 
                                   normal overload resolution

Why useful?
You can provide different behaviors for the same conceptual operation.
Makes code easier to read and more flexible 

These cannot be overloaded at all:
:: (Scope resolution)
. (Dot operator)
.* (Pointer-to-member)
?: (Ternary conditional)

These are operators, but they work on compile-time language features, 
so overloading makes no sense:
sizeof
typeid
alignof
Cast operators (static_cast, dynamic_cast, reinterpret_cast, const_cast)
noexcept

new and delete operators can be overloaded globally or per class, 
but placement new syntax (void* operator new(size_t, void*)) 
is not overloadable by the user.

*/

#include <iostream>

void greet() 
{
    std::cout << "Hello!\n";
}

void greet(const std::string& name) 
{
    std::cout << "Hello, " << name << "!\n";
}

void greet(int times) 
{
    for (int i = 0; i < times; ++i) 
    {
        std::cout << "Hello!\n";
    }
}

int main() {
    greet();                    // Calls greet()
    greet("Alice");              // Calls greet(string)
    greet(3);                    // Calls greet(int)
    return 0;
}
