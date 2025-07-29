/*
Semaphore in Modern C++ (C++20)
C++20 introduced semaphores in the <semaphore> header
1. std::counting_semaphore<max_value> — a counting semaphore.
2. std::binary_semaphore — a binary semaphore (special case where max_value = 1).
*/

**************************Counting Semaphore***************************
#include <iostream>
#include <thread>
#include <semaphore>
#include <chrono>

using namespace std;

// Allow max 2 threads to access resource at a time
counting_semaphore<2> semaphore(2);

void access_resource(int id) 
{
    cout << "Thread " << id << " is waiting...\n";
    semaphore.acquire();  // wait for permit

    cout << "Thread " << id << " is accessing resource\n";
    this_thread::sleep_for(chrono::seconds(2)); // simulate work

    cout << "Thread " << id << " is done\n";
    semaphore.release();  // release permit
}

int main() 
{
    // Create threads in a simple loop
    thread t1(access_resource, 1);
    thread t2(access_resource, 2);
    thread t3(access_resource, 3);
    thread t4(access_resource, 4);

    // Join threads
    t1.join();
    t2.join();
    t3.join();
    t4.join();

    cout << "All threads finished\n";
    return 0;
}

/*
🖨️ SAMPLE OUTPUT:
Thread 1 is waiting...
Thread 1 is accessing resource
Thread 2 is waiting...
Thread 2 is accessing resource
Thread 3 is waiting...
Thread 4 is waiting...
Thread 1 is done
Thread 3 is accessing resource
...
*/

/*
What happens here?
The semaphore is initialized with a count of 3.
meaning up to 3 threads can enter the critical section at the same time.
Threads calling acquire() will block if the count is zero (i.e., 3 threads are already inside).
After the thread finishes, 
it calls release() to increment the count, allowing other blocked threads to proceed.
*/
