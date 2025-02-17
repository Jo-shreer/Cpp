#include <iostream>
#include <string>
using namespace std;

class Person {
private:
    string name;
    int age;

public:
    // Parameterized constructor
    Person(const string& name, int age) : name(name), age(age) {
        cout << "Parameterized constructor called for " << name << endl;
    }
    // Copy constructor
    Person(const Person& other) : name(other.name), age(other.age) {
        cout << "Copy constructor called for " << name << endl;
    }
    // Method to display person's information
    void display() const {
        cout << "Name: " << name << ", Age: " << age << endl;
    }
};

int main() 
{
    // Creating an object using the parameterized constructor
    Person person1("Alice", 30);
    person1.display();
    // Creating a copy of person1 using the copy constructor
    Person person2 = person1;  // This calls the copy constructor
    person2.display();

    return 0;
}


*****************************************************************************************************************
OR
*****************************************************************************************************************

class Base
{
    int *p;
    
    public:
    Base()
    {
        p = nullptr;
    }
    
    Base(int value)
    {
        p = new int(value);
    }
    
    Base(const Base &b1)
    {
        p = new int(*b1.p);
    }
    
    void print()
    {
        cout << *p << endl;
    }
};
int main()
{
    Base b1(2);
    Base b2 = b1;
    b1.print();
    b2.print();
    
}
