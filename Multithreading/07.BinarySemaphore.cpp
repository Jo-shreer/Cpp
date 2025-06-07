/*
A binary semaphore is a special kind of semaphore that can only take two values: 0 or 1.
It’s essentially a mutex-like synchronization primitive but with no ownership semantics.
Used to control access to a single shared resource between threads.
Available in C++20 under the <semaphore> header.

How std::binary_semaphore Works
Initialized with a count of 0 or 1.
acquire() decreases the count; if it’s already 0, the calling thread blocks.
release() increases the count; if threads are waiting, one is unblocked.
Unlike std::mutex, any thread can call release() (no ownership).
*/

#include <iostream>
#include <thread>
#include <semaphore>
using namespace std;

std::binary_semaphore semaphore(1);  // starts unlocked (count=1)

void worker(int id) 
{
    cout << "Thread " << id << " waiting to enter critical section...\n";
    semaphore.acquire();  // wait / lock
  
    cout << "Thread " << id << " entered critical section.\n";
    this_thread::sleep_for(chrono::seconds(1)); // simulate work
  
    cout << "Thread " << id << " leaving critical section.\n";
    semaphore.release();  // signal / unlock
}

int main() 
{
    thread t1(worker, 1);
    thread t2(worker, 2);
    t1.join();
    t2.join();
    return 0;
}

