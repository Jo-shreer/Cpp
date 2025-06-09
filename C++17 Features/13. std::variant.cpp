/*
std::variant is a type-safe union — holds one of several types.

Before C++17:
Representing a variable that can hold one of many types required:
Unions (unsafe for non-trivial types).
Complex class hierarchies with pointers and virtual functions.
Boost.Variant (third-party library).

Why is it better?
Type-safe, no manual union hacks.
Easy to use with std::visit for handling the active type.
Improves code clarity and safety.

*/

#include <iostream>
#include <variant>

int main() 
{
    std::variant<int, std::string> v;
    v = 10;
    std::cout << "Int: " << std::get<int>(v) << "\n";
    v = "Hello";
    std::cout << "String: " << std::get<std::string>(v) << "\n";
    return 0;
}

op
Int: 10
String: Hello
  
