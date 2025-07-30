/*
Why use make_shared?
1. Efficiency: fewer allocations
make_shared allocates one block of memory that holds both the control 
block (reference counts, etc.) and the actual object.
If you do shared_ptr<T> sp(new T(...));, it does two separate allocations — 
one for the control block and one for the object.
Fewer allocations mean better performance and less memory fragmentation.

2. Exception safety
When you do shared_ptr<T> sp(new T(...)); if the new T(...) 
throws, memory can leak.
make_shared is exception-safe, meaning it handles object creation and
control block setup atomically.

3. Cleaner, safer syntax
Avoids the raw new keyword, making your code cleaner and less error-prone.
    */

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
