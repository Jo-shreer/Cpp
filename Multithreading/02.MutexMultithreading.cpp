/*
1. A mutex (short for mutual exclusion) is a synchronization
primitive in C++ used to protect shared resources 
from being accessed concurrently by multiple threads. 
2. When multiple threads access the same data, 
a mutex ensures that only one thread can access that data at a time, 
preventing race conditions.

Locking and Unlocking:
Locking a mutex: A thread locks the mutex before accessing the shared resource.
Unlocking a mutex: After finishing its work, 
the thread unlocks the mutex, allowing another thread to lock it and access the resource.

By using a mutex, you ensure that shared data is protected 
from being modified simultaneously by multiple threads, 
which could lead to inconsistent or unpredictable results.

A mutex mtx is declared at the global level to control access to the
shared resource (in this case, std::cout).
The std::lock_guard<std::mutex> is used to automatically lock and unlock 
the mutex. 
When the lock_guard object goes out of scope (i.e., at the end of the function), it automatically unlocks the mutex.
The threads t1 and t2 both attempt to access std::cout, 
but because std::cout is shared, 
the mutex ensures that only one thread prints at a time.

Important Mutex Types in C++:
1. std::mutex:
Basic mutex for protecting shared resources.
It has two main methods: lock() and unlock().

2. std::lock_guard:
A RAII-style (Resource Acquisition Is Initialization) lock that automatically 
locks the mutex when created and unlocks it when it goes out of scope.
Ideal for simple lock/unlock use cases.

3. std::unique_lock:
Provides more flexibility than std::lock_guard. You can manually lock and
unlock the mutex using lock() and unlock().
It is also more versatile as it can be used with condition variables.

4. std::recursive_mutex:
Allows a thread to lock the mutex multiple times without causing a deadlock, 
unlike a regular mutex that would block if the same thread tries to lock it 
again.std::timed_mutex and std::try_mutex:

These variants allow you to try to lock the mutex for a 
limited time (timed_mutex) or 
attempt to lock without blocking (try_mutex).
*/

**********************************Race condition*************************************
/*Race Condition
A race condition happens when two or more threads access shared data at the same time, 
and the final result depends on the timing of how the threads run.

Use mutexes or atomic variables
*/
    
#include <iostream>
#include <thread>
using namespace std;

int counter = 0;
void increment() 
{
    for (int i = 0; i < 1000; ++i) 
    {
        ++counter;  // Not thread-safe
    }
}

int main() 
{
    thread t1(increment);
    thread t2(increment);
    t1.join();
    t2.join();
    cout << "Counter: " << counter << endl;  // Might be < 2000
    return 0;
}

*********************************Use Mutex**************************************
#include <iostream>
#include <thread>
#include <mutex>
using namespace std; 
mutex mtx;                // Create a mutex

void print_numbers(int id) 
{
    lock_guard<mutex> lock(mtx);  // Lock the mutex automatically
    cout << "Thread " << id << " is accessing shared resource\n";
}

int main() 
{
    thread t1(print_numbers, 1);
    thread t2(print_numbers, 2);
    t1.join();
    t2.join();
    return 0;
}

/* Deadlock 
occurs when two or more threads are waiting on each other to release resources, 
and none of them can proceed — like a circular wait.
Fix	 - Use consistent lock order, std::lock
Simple Code Example (BAD — Causes Deadlock):
*/

#include <iostream>
#include <thread>
#include <mutex>
using namespace std;
mutex mutex1, mutex2;

void threadA() 
{
    lock_guard<mutex> lock1(mutex1);
    this_thread::sleep_for(chrono::milliseconds(100));
    lock_guard<mutex> lock2(mutex2);
    cout << "Thread A finished\n";
}
void threadB() 
{
    lock_guard<mutex> lock2(mutex2);
    this_thread::sleep_for(chrono::milliseconds(100));
    lock_guard<mutex> lock1(mutex1);
    cout << "Thread B finished\n";
}

int main() 
{
    thread t1(threadA);
    thread t2(threadB);
    t1.join();
    t2.join();
    return 0;
}

