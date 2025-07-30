#include <iostream>
#include <memory>

using namespace std;

class MyClass 
{
    public:
    void sayHello() 
    {
        cout << "Hello!\n";
    }
};

int main() 
{
    shared_ptr<MyClass> sp = make_shared<MyClass>();

    // Using arrow operator (most common)
    sp->sayHello();

    // Using dereference operator and dot
    (*sp).sayHello();

    return 0;
}


Hello!
Hello!
  
