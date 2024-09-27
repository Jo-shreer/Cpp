#include <iostream>

class Base {
public:
    virtual void show() {
        std::cout << "Base class show" << std::endl;
    }
};

class Derived : public Base {
public:
    void show() final { // Cannot be overridden
        std::cout << "Derived class show" << std::endl;
    }
};

// Attempting to override the show method in a further derived class will cause a compile error
// class FurtherDerived : public Derived {
// public:
//     void show() override { } // Uncommenting this will give an error
// };

int main() {
    Derived d;
    d.show(); // Calls Derived's show
    return 0;
}
