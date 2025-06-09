/*
std::string_view represents a non-owning, read-only view of a string.

Before C++17:
Passing strings around often meant copying std::string or 
using raw pointers plus size — error-prone and inefficient.

Why better?
No copying of strings, just references.
Useful for APIs that accept strings without taking ownership.
Safer and more efficient than raw pointers.
*/

#include <iostream>
#include <string_view>

void print(std::string_view sv) 
{
    std::cout << "String_view: " << sv << "\n";
}

int main() 
{
    std::string str = "Hello, World!";
    print(str);
    print("Literal string");

    return 0;
}

op
String_view: Hello, World!
String_view: Literal string
