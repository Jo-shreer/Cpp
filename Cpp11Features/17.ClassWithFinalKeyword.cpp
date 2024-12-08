/*
In C++, the final keyword is used to indicate that a function or class cannot be further overridden or inherited, respectively.
It was introduced in C++11 to enhance control over class inheritance and polymorphism. The final keyword provides a way to prevent unintended 
overriding or further inheritance, which helps improve code safety and clarity.
Use of final in C++
Final for Virtual Functions: The final keyword can be applied to virtual functions to indicate that they cannot be overridden by any derived class.
Final for Classes: The final keyword can be applied to a class to prevent it from being inherited by any other class.

*/

#include <iostream>

class Base 
{
    public:
    void show() {
        std::cout << "Base class" << std::endl;
    }
};

// Final class
class FinalClass final 
{
    public:
    void display() 
    {
        std::cout << "Final class" << std::endl;
    }
};

// Attempting to derive from FinalClass will cause a compile error
// class Derived : public FinalClass { }; // Uncommenting this will give an error

int main() 
{
    FinalClass fc;
    fc.display();
    return 0;
}
