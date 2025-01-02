/*
The override keyword in C++ is used to explicitly indicate that a function is intended to override a virtual function in a base class.
Purpose of the override Keyword:
Clarification: It makes the programmer's intent clear, signaling that a function is meant to override a base class virtual function.
Error Prevention: If the function does not actually override a virtual function (due to a mismatch in the function signature or because the base class 
function is not virtual), the compiler will generate an error. This prevents subtle bugs that might arise from incorrectly overriding a function.
*/
#include <iostream>

class Base 
{
    public:
    virtual void print() 
    {
        std::cout << "Base class print" << std::endl;
    }
};

class Derived : public Base 
{
public:
    void print() override // Correctly overrides Base::print
    {
        std::cout << "Derived class print" << std::endl;
    }
    // Uncommenting the following will cause a compile-time error
    // void print(int) override { } // Error: No matching base class function
};

int main() {
    Base* b = new Derived();
    b->print();  // Calls Derived's print
    delete b;
    return 0;
}
