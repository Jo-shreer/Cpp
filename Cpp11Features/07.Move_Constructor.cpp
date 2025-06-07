/*A move constructor in C++ is a special constructor that allows an object to "steal" resources from a temporary object (an rvalue). 
This avoids deep copying of resources, improving performance,especially when dealing with large objects or resources 
like dynamically allocated memory, file handles, or other system resources.*/

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
