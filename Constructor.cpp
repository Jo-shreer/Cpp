#include <iostream>
#include <string>

class Person {
private:
    std::string name;
    int age;

public:
    // Constructor with parameters
    Person(const std::string& name, int age) : name(name), age(age) {
        std::cout << "Constructor called for " << name << " who is " << age << " years old." << std::endl;
    }

    // Default constructor
    Person() : name("Unknown"), age(0) {
        std::cout << "Default constructor called." << std::endl;
    }

    // Method to display person's information
    void display() const {
        std::cout << "Name: " << name << ", Age: " << age << std::endl;
    }
};

int main() {
    // Creating an object using the parameterized constructor
    Person person1("Alice", 30);
    person1.display();

    // Creating an object using the default constructor
    Person person2;
    person2.display();

    return 0;
}
