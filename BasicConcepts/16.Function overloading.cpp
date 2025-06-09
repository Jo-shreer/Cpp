/*
Function overloading means you can have multiple functions with the same name
but with different parameters.
The compiler chooses the correct function based on:
Number of parameters
Types of parameters

Why useful?
You can provide different behaviors for the same conceptual operation.
Makes code easier to read and more flexible 
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
