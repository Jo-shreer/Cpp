#include <iostream>
#include <set>
#include <string>
using namespace std;

class Person 
{
    private:
    string name;
    int age;

    public:
    Person(const string& name, int age) : name(name), age(age) {}

    bool operator<(const Person& other) const 
    {
        return name < other.name; // Compare by name
    }
    void display() const 
    {
        cout << "Name: " << name << ", Age: " << age << endl;
    }
};

int main() 
{
    set<Person> people;
    people.insert(Person("Alice", 30));
    people.insert(Person("Bob", 25));
    people.insert(Person("Charlie", 35));
    people.insert(Person("Alice", 30)); // Duplicate, won't be added

    for (const auto& person : people) 
    {
        person.display();
    }

    return 0;
}
