#include <iostream>

class UniqueIntPtr
{
    private:
    int* ptr;

    public:
    explicit UniqueIntPtr(int* p = nullptr) : ptr(p) {}

    // Delete copy constructor and copy assignment
    UniqueIntPtr(const UniqueIntPtr&) = delete;
    UniqueIntPtr& operator=(const UniqueIntPtr&) = delete;

    // Move constructor
    UniqueIntPtr(UniqueIntPtr&& other) noexcept 
    {
        ptr = other.ptr;
        other.ptr = nullptr;
    }
    // Move assignment
    UniqueIntPtr& operator=(UniqueIntPtr&& other) noexcept 
    {
        if (this != &other) 
        {
            delete ptr;
            ptr = other.ptr;
            other.ptr = nullptr;
        }
        return *this;
    }
    // Destructor
    ~UniqueIntPtr() 
    {
        delete ptr;
    }
    // Dereference operators
    int& operator*() const { return *ptr; }
    int* operator->() const { return ptr; }

    // Get raw pointer
    int* get() const { return ptr; }

    // Release ownership
    int* release() 
    {
        int* temp = ptr;
        ptr = nullptr;
        return temp;
    }
    // Reset the pointer
    void reset(int* p = nullptr) 
    {
        delete ptr;
        ptr = p;
    }
};

/**************************************************************************************************

#include <iostream>
#include <utility> // For std::move

template <typename T>
class UniquePtr 
{
    private:
    T* ptr; // Pointer to the managed object

    public:
    // Constructor
    explicit UniquePtr(T* p = nullptr) : ptr(p) {}

    // Destructor
    ~UniquePtr() 
    {
        delete ptr; // Automatically delete the managed object
    }

    // Move constructor
    UniquePtr(UniquePtr&& other) noexcept : ptr(other.ptr) 
    {
        other.ptr = nullptr; // Transfer ownership and nullify other
    }

    // Move assignment operator
    UniquePtr& operator=(UniquePtr&& other) noexcept 
   {
        if (this != &other) {
            delete ptr;       // Delete current managed object
            ptr = other.ptr;  // Transfer ownership
            other.ptr = nullptr; // Nullify other
        }
        return *this;
    }

    // Delete copy constructor and copy assignment operator
    UniquePtr(const UniquePtr&) = delete;
    UniquePtr& operator=(const UniquePtr&) = delete;

    // Access operators
    T& operator*() const 
    {
        return *ptr; // Dereference operator
    }

    T* operator->() const 
    {
        return ptr; // Member access operator
    }

    // Get the raw pointer
    T* get() const 
    {
        return ptr;
    }

    // Release ownership of the managed object
    T* release() 
    {
        T* temp = ptr;
        ptr = nullptr; // Nullify the pointer
        return temp;   // Return the raw pointer
    }

    // Reset the managed object
    void reset(T* p = nullptr) 
    {
        delete ptr; // Delete the currently managed object
        ptr = p;    // Take ownership of the new pointer
    }
};

class MyClass 
{
    public:
    MyClass() { std::cout << "MyClass constructed" << std::endl; }
    ~MyClass() { std::cout << "MyClass destructed" << std::endl; }
    void greet() { std::cout << "Hello from MyClass!" << std::endl; }
};

int main() 
{
    // Create a UniquePtr managing a MyClass object
    UniquePtr<MyClass> myPtr(new MyClass());
    myPtr->greet();

    // Move ownership to another UniquePtr
    UniquePtr<MyClass> anotherPtr = std::move(myPtr);
    
    if (!myPtr.get()) 
    {
        std::cout << "myPtr is now null after move." << std::endl;
    }

    return 0; // anotherPtr will automatically clean up the MyClass instance
}
