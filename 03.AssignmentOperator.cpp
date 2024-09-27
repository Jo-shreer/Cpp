//The assignment operator in C++ allows you to assign the contents of one object to another object of the same class. 
//When you define your own assignment operator, you can ensure that the resources are managed properly (especially for classes that manage dynamic memory). 

#include <iostream>
#include <string>
using namespace std;

class Person 
{
private:
    string name;
    int age;

public:
    // Parameterized constructor
    Person(const string& name, int age) : name(name), age(age) 
    {
        cout << "Parameterized constructor called for " << name << endl;
    }

    // Copy constructor
    Person(const Person& other) : name(other.name), age(other.age) 
    {
        cout << "Copy constructor called for " << name << endl;
    }

    // Assignment operator
    Person& operator=(const Person& other) 
    {
        if (this != &other) // Self-assignment check
        { 
            name = other.name;
            age = other.age;
            cout << "Assignment operator called for " << name << endl;
        }
        return *this; // Return the current object
    }
    void display() const 
    {
        cout << "Name: " << name << ", Age: " << age << endl;
    }
};

int main() 
{
    Person person1("Alice", 30);
    person1.display();

    // Creating a copy of person1 using the copy constructor
    Person person2 = person1;  // This calls the copy constructor
    person2.display();

    // Assigning person1 to person2 using the assignment operator
    Person person3("Bob", 25);
    person3.display();
    
    person3 = person1;  // This calls the assignment operator
    person3.display();

    return 0;
}
