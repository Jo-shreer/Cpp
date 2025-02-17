#include <iostream>
#include <cstdlib>

// Overriding the global new operator
void* operator new(std::size_t size) 
{
    std::cout << "Custom new called, size: " << size << std::endl;
    void* ptr = std::malloc(size);  
    if (!ptr) 
    {
        throw std::bad_alloc(); 
    }
    return ptr;
}

// Overriding the global delete operator
void operator delete(void* ptr) noexcept 
{
    std::cout << "Custom delete called" << std::endl;
    std::free(ptr);  

class MyClass 
{
    public:
    int x;
    MyClass(int val) : x(val) {}
};

int main() 
{
    MyClass* obj = new MyClass(10);
    std::cout << "MyClass value: " << obj->x << std::endl;
    delete obj;
    return 0;
}
