/*
A mutex (short for mutual exclusion) is a synchronization primitive in C++ used to protect shared resources 
from being accessed concurrently by multiple threads. 
When multiple threads access the same data, a mutex ensures that only one thread can access that data at a time, 
preventing race conditions.
Locking and Unlocking:
Locking a mutex: A thread locks the mutex before accessing the shared resource.
Unlocking a mutex: After finishing its work, the thread unlocks the mutex, 
allowing another thread to lock it and access the resource.
By using a mutex, you ensure that shared data is protected from being modified simultaneously by multiple threads, 
which could lead to inconsistent or unpredictable results.
*/

#include <iostream>
#include <thread>
#include <mutex>
std::mutex mtx;  // Create a mutex

void print_numbers(int id) 
{
    std::lock_guard<std::mutex> lock(mtx);  // Lock the mutex automatically
    std::cout << "Thread " << id << " is accessing shared resource\n";
}

int main() 
{
    std::thread t1(print_numbers, 1);
    std::thread t2(print_numbers, 2);
    t1.join();
    t2.join();
    return 0;
}

    t1.join();
    t2.join();

    return 0;
}
