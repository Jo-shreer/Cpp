/*

What is Atomicity?
An operation is atomic if it happens completely or not at all, 
with no partial effects visible to other threads.

Atomic operations are indivisible and uninterruptible:
no other thread can see an intermediate or inconsistent 
state during that operation.

In multithreading, atomicity is crucial to prevent race conditions, 
where two or more threads try to read/write shared data simultaneously 
and cause unpredictable results.
    */

#include <iostream>
#include <thread>
#include <vector>
#include <memory>
#include <atomic>
#include <chrono>

using namespace std;

class Data 
{
    public:
    int value;
    Data(int v) : value(v) {}
};

// Shared atomic pointer to Data
atomic<shared_ptr<Data>> sharedData;

void reader(int id) 
{
    for (int i = 0; i < 5; ++i) 
    {
        // Load shared_ptr atomically
        shared_ptr<Data> localPtr = atomic_load(&sharedData);
        cout << "Reader " << id << " reads value: " << localPtr->value << endl;
        this_thread::sleep_for(chrono::milliseconds(100));
    }
}

void writer() 
{
    for (int i = 1; i <= 3; ++i) 
    {
        // Load current data snapshot
        shared_ptr<Data> current = atomic_load(&sharedData);

        // Make a private copy to modify
        shared_ptr<Data> newData = make_shared<Data>(*current);
        newData->value += 10 * i;  // Modify the copy

        // Simulate some work on copy
        this_thread::sleep_for(chrono::milliseconds(250));

        // Atomically swap the updated data in
        atomic_store(&sharedData, newData);

        cout << "Writer updated value to " << newData->value << endl;

        // Wait before next update
        this_thread::sleep_for(chrono::milliseconds(300));
    }
}

int main() 
{
    // Initialize shared data
  
    sharedData = make_shared<Data>(0);
    // Start multiple readers
  
    vector<thread> readers;
    for (int i = 0; i < 3; ++i) 
    {
        readers.emplace_back(reader, i + 1);
    }

    // Start writer thread
    thread w(writer);

    // Join threads
    for (auto& r : readers) r.join();
    w.join();

    return 0;
}
