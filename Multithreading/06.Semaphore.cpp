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
#include <vector>

using namespace std;

std::counting_semaphore<3> semaphore(3); // max 3 threads can enter concurrently

void task(int id) 
{
    semaphore.acquire();  // wait / decrement
    cout << "Thread " << id << " is inside critical section.\n";
    
  // Simulate work
    this_thread::sleep_for(chrono::seconds(1));
  
    cout << "Thread " << id << " leaving critical section.\n";
    semaphore.release();  // signal / increment
}

int main() 
{
    vector<thread> threads;
    // Launch 6 threads
    for (int i = 0; i < 6; ++i) 
    {
        threads.emplace_back(task, i);
    }
    for (auto& t : threads) 
    {
        t.join();
    }
    return 0;
}
/*
What happens here?
The semaphore is initialized with a count of 3.
meaning up to 3 threads can enter the critical section at the same time.
Threads calling acquire() will block if the count is zero (i.e., 3 threads are already inside).
After the thread finishes, 
it calls release() to increment the count, allowing other blocked threads to proceed.
*/
