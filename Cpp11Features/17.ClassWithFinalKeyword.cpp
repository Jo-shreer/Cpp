#include <iostream>

class Base {
public:
    void show() {
        std::cout << "Base class" << std::endl;
    }
};

// Final class
class FinalClass final {
public:
    void display() {
        std::cout << "Final class" << std::endl;
    }
};

// Attempting to derive from FinalClass will cause a compile error
// class Derived : public FinalClass { }; // Uncommenting this will give an error

int main() {
    FinalClass fc;
    fc.display();
    return 0;
}
