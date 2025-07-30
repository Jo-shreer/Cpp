#include <iostream>
#include <memory>

using namespace std;

class MyClass 
{
    public:
    void greet() { cout << "Hello!\n"; }
};

int main() 
{
    shared_ptr<MyClass> sp = make_shared<MyClass>();
    MyClass* rawPtr = sp.get();  // get the raw pointer
    rawPtr->greet();

    return 0;
}

op
Hello!
