/* 
Move constructor in C++ is a special constructor 
1. Allows an object to "steal" resources from a temporary object (an rvalue). 
2. This avoids deep copying of resources, improving performance,
especially when dealing with large objects or resources 
like dynamically allocated memory, file handles, or other system resources.*/

#include <iostream>

class MyClass 
{
    private:
    int* ptr;

    public:
    MyClass(int value) 
    {
        ptr = new int(value);
    }

    // Destructor
    ~MyClass() 
    {
        delete ptr;
    }

    // Copy Constructor
    MyClass(const MyClass& other) 
   {
        ptr = new int(*other.ptr); // Deep copy
        std::cout << "Copy Constructor\n";
    }

    // Move Constructor
    MyClass(MyClass&& other) noexcept 
    {
        ptr = other.ptr;           // Transfer ownership
        other.ptr = nullptr;       // Nullify source
        std::cout << "Move Constructor\n";
    }

    // Print value
    void print() const 
    {
        if (ptr)
            std::cout << "Value: " << *ptr << std::endl;
        else
            std::cout << "Null pointer\n";
    }
};

int main() 
{
    MyClass a(10);      // Constructor
    MyClass b = std::move(a);  // Move Constructor
    a.print();  // Should print "Null pointer"
    b.print();  // Should print "Value: 10"
}

*************************************************************************************************************
#include <iostream>

class MyClass 
{
private:
    int* data; 

public:
    MyClass(int val) 
    {
        data = new int(val); 
        std::cout << "Constructor: Allocating memory of size " << size << std::endl;
    }
    MyClass(MyClass&& other) noexcept : data(other.data) 
    {
        other.data = nullptr;
        std::cout << "Move Constructor: Transferred resource!" << std::endl;
    }

    // Destructor
    ~MyClass() 
    {
        if (data) 
        {
            delete[] data;  
            std::cout << "Destructor: Releasing memory" << std::endl;
        }
    }
    void useData() 
    {
        std::cout << "Using data..." << std::endl;
    }
};

int main() {
    MyClass obj1(10);  
    obj1.useData();
    MyClass obj2 = std::move(obj1);  // Move constructor is called here
    obj2.useData(); 
    return 0;
}
