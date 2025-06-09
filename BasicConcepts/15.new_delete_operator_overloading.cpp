#include <iostream>
#include <new>  // Required for placement new

// Overriding global new operator (without malloc)
void* operator new(std::size_t size) 
{
    std::cout << "Custom new called, size: " << size << std::endl;
    void* ptr = ::operator new(size);  
    if (!ptr) 
    {
        throw std::bad_alloc();  // Throw exception if allocation fails
    }
    return ptr;
}

// Overriding global delete operator (without free)
void operator delete(void* ptr) noexcept 
{
    std::cout << "Custom delete called" << std::endl;
    ::operator delete(ptr);  // Use C++ operator delete
}

class MyClass 
{
    public:
    int x;
    MyClass(int val) : x(val) {}
};

int main() {
    // Using the new operator (which will call the custom new)
    MyClass* obj = new MyClass(10);
    std::cout << "MyClass value: " << obj->x << std::endl;
    // Using the delete operator (which will call the custom delete)
    delete obj;
    return 0;
}
