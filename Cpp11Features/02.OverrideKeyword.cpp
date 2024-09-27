#include <iostream>

class Base {
public:
    virtual void print() {
        std::cout << "Base class print" << std::endl;
    }
};

class Derived : public Base {
public:
    void print() override { // Correctly overrides Base::print
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
