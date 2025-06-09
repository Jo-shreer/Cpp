/*
If you plan to delete a derived object via a base class pointer,
the base class must have a virtual destructor.

Why?
If the destructor is not virtual, 
then deleting through a base class pointer will only call the base destructor — 
the derived destructor won’t run → this causes resource leaks.

Rule of Thumb:
✅ If your base class is meant to be used polymorphically
(with virtual functions or used via base pointers),
you should declare its destructor as virtual.

*/
#include <iostream>

class Base 
{
    public:
    Base() { std::cout << "Base constructor\n"; }
    virtual ~Base() { std::cout << "Base destructor\n"; } // Virtual destructor!
};

class Derived : public Base 
{
    public:
    Derived() { std::cout << "Derived constructor\n"; }
    ~Derived() { std::cout << "Derived destructor\n"; }
};

int main() 
{
    Base* ptr = new Derived();  // Create Derived object through Base pointer
    delete ptr;                 // Now both destructors will be called!

    return 0;
}

op
Base constructor
Derived constructor
Derived destructor
Base destructor

