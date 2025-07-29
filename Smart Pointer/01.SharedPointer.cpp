*********************************Without Template*****************************************

#include <iostream>

class SharedPtr 
{
    private:
    int *ptr;          // Raw pointer to int
    int *ref_count;    // Pointer to reference count

    public:
    explicit SharedPtr(int* p = nullptr) : ptr(p), ref_count(new int(1)) 
    {
        // std::cout << "SharedPtr constructed\n";
    }

    // Copy constructor
    SharedPtr(const SharedPtr &other) 
    {
        ptr = other.ptr;
        ref_count = other.ref_count;
        ++(*ref_count);
        // std::cout << "SharedPtr copied, count = " << *ref_count << "\n";
    }

    // Assignment operator
    SharedPtr& operator=(const SharedPtr& other) 
    {
        if (this != &other) 
        {
            release();
            ptr = other.ptr;
            ref_count = other.ref_count;
            ++(*ref_count);
        }
        return *this;
    }

    // Destructor
    ~SharedPtr() 
    {
        release();
    }

    // Dereference operator
    int& operator*() const { return *ptr; }
    int* operator->() const { return ptr; }

    // Get raw pointer
    int* get() const { return ptr; }

    // Get current use count
    int use_count() const { return *ref_count; }

private:
    void release() 
     {
        --(*ref_count);
        if (*ref_count == 0) 
        {
            delete ptr;
            delete ref_count;
            // std::cout << "SharedPtr destroyed\n";
        }
    }
};

int main() 
{
    SharedPtr sp1(new int(42));
    {
        SharedPtr sp2 = sp1;
        std::cout << "Value: " << *sp2 << "\n";                   // 42
        std::cout << "Use count: " << sp1.use_count() << "\n";    // 2
    } // sp2 destroyed, count decremented

    std::cout << "Use count after sp2 destroyed: " << sp1.use_count() << "\n"; // 1
    std::cout << "Value: " << *sp1 << "\n";             // 42
    return 0;
}

o/p
Value: 42
Use count: 2
Use count after sp2 destroyed: 1
Value: 42



*************************************************with Template***********************************
#include <iostream>

template<typename T>
class SharedPtr {
private:
    T* ptr;               // Raw pointer to the object
    int* ref_count;       // Pointer to reference count

public:
    // Constructor
    explicit SharedPtr(T* p = nullptr) : ptr(p), ref_count(new int(1)) {
        // std::cout << "SharedPtr constructed\n";
    }

    // Copy constructor: increase ref count
    SharedPtr(const SharedPtr& other) {
        ptr = other.ptr;
        ref_count = other.ref_count;
        ++(*ref_count);
        // std::cout << "SharedPtr copied, count = " << *ref_count << "\n";
    }

    // Assignment operator
    SharedPtr& operator=(const SharedPtr& other) {
        if (this != &other) {
            // Decrease old ref count and delete if needed
            release();

            // Copy from other
            ptr = other.ptr;
            ref_count = other.ref_count;
            ++(*ref_count);
        }
        return *this;
    }

    // Destructor: decrease ref count and delete if zero
    ~SharedPtr() {
        release();
    }

    // Dereference operators
    T& operator*() const { return *ptr; }
    T* operator->() const { return ptr; }

    // Get raw pointer
    T* get() const { return ptr; }

    // Get current use count
    int use_count() const { return *ref_count; }

private:
    void release() {
        --(*ref_count);
        if (*ref_count == 0) {
            delete ptr;
            delete ref_count;
            // std::cout << "SharedPtr destroyed\n";
        }
    }
};
