#include <iostream>
#include <memory>

using namespace std;

class MyClass 
{
    public:
    MyClass() 
    {
        cout << "MyClass constructor called\n";
    }

    ~MyClass() 
    {
        cout << "MyClass destructor called\n";
    }

    void greet() 
    {
        cout << "Hello from MyClass!\n";
    }
};

int main() 
{
    shared_ptr<MyClass> sp1 = make_shared<MyClass>();
    sp1->greet();
    cout << "Use count: " << sp1.use_count() << "\n";
    shared_ptr<MyClass> sp2 = sp1;
    sp2->greet();
    cout << "Use count inside block: " << sp1.use_count() << "\n";
    // sp2 goes out of scope here

    cout << "Use count after block: " << sp1.use_count() << "\n";

    return 0;
}
