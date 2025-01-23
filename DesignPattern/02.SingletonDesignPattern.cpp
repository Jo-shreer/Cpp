/*The Singleton Design Pattern is a creational design pattern that ensures a class has only one instance and provides a global point of access
to that instance. It is used when exactly one object is needed to coordinate actions across the system.
Characteristics of the Singleton Pattern:
Single Instance: There is only one instance of the class throughout the program.
Global Access: The single instance is accessible globally, often via a static method.
Lazy Initialization: The instance is created when it is first needed (this can be optional, depending on the implementation).
Thread-Safety: In multithreaded environments, care must be taken to ensure that the instance is created safely.
Use Cases for Singleton Pattern:
When you need a shared resource, such as a logging object, configuration manager, or database connection that needs to be accessed by multiple parts 
of the program, and you want to ensure only one instance of the resource exists.
*/

#include <iostream>
using namespace std;

class Singleton
{
    private:
    static Singleton *instance;
    Singleton() {}    //private constructor

    public:
    Singleton(const Singleton &s) = delete;
    Singleton& operator=(const Singleton &s) = delete;
    
    static Singleton* getInstance()
    {
        if(instance == nullptr)
        {
           return instance = new Singleton(); 
        }
    }
    void dosomething()
    {
        cout << "Do something" << endl;
    }
    ~Singleton() {}
};

Singleton* Singleton::instance = nullptr;

int main()
{
    Singleton *s1 = Singleton::getInstance();
    s1->dosomething();
    Singleton *s2 = Singleton::getInstance();
    s2->dosomething();
    if(s1 == s2)
    {
        cout<< "Both are same insatnce" << endl;   
    }
    return 0;
}
