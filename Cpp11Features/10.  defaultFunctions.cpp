#include <iostream>

class MyClass {
public:
    MyClass() = default; // Default constructor
    ~MyClass() = default; // Default destructor

    MyClass(const MyClass&) = default; // Default copy constructor
    MyClass& operator=(const MyClass&) = default; // Default assignment operator

    void display() {
        std::cout << "MyClass instance" << std::endl;
    }
};

int main() {
    MyClass obj1; // Calls default constructor
    MyClass obj2 = obj1; // Calls default copy constructor
    obj2.display();

    MyClass obj3;
    obj3 = obj1; // Calls default assignment operator
    obj3.display();

    return 0;
}
