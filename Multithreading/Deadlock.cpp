/*Common Strategies:
Lock ordering (most practical)
Always acquire locks in a fixed global order.

Example: if both threads need mutex1 and mutex2, always lock mutex1 
before mutex2.

Try-lock with timeout
Use std::try_lock or timed mutexes.
If you can’t acquire all locks, release what you hold and retry.
Prevents indefinite waiting.
  
Deadlock detection
Monitor resource wait graphs, detect cycles, 
and abort/restart one of the threads.

Often used in databases.

Reduce resource locking
Use finer-grained locks or lock-free data structures
(std::atomic, lock-free queues).
Reduces the chance of cycles forming.
*/
deadlock

#include <iostream>
#include <thread>
#include <mutex>
using namespace std;

mutex mtx1, mtx2;
void task1() 
{
    lock_guard<mutex> lock1(mtx1);
    this_thread::sleep_for(chrono::milliseconds(100)); // simulate work
    lock_guard<mutex> lock2(mtx2);  // waits here
    cout << "Task1 finished\n";
}

void task2() 
{
    lock_guard<mutex> lock2(mtx2);
    this_thread::sleep_for(chrono::milliseconds(100)); // simulate work
    lock_guard<mutex> lock1(mtx1);  // waits here
    cout << "Task2 finished\n";
}

int main() 
{
    thread t1(task1);
    thread t2(task2);

    t1.join();
    t2.join();
}

fix - Fix with std::try_lock (avoiding indefinite wait)

#include <iostream>
#include <thread>
#include <mutex>
using namespace std;

mutex mtx1, mtx2;

void tryLockTask() 
{
    while (true) 
    {
        if (try_lock(mtx1, mtx2) == -1) 
        {  // success
            cout << "Work done safely\n";
            mtx1.unlock();
            mtx2.unlock();
            break;
        } 
        else 
        {
            // Failed to acquire both locks, retry
            this_thread::yield(); 
        }
    }
}

int main() 
{
    thread t1(tryLockTask);
    thread t2(tryLockTask);

    t1.join();
    t2.join();
}

How it Works
Two mutexes (mtx1, mtx2) are shared between threads.
Both threads (t1, t2) run the same function tryLockTask().
Inside tryLockTask():
try_lock(mtx1, mtx2) attempts to lock both mutexes at the same time.
If it succeeds (== -1):
Both mutexes are locked → safe to do work.
Work is done (cout), then both mutexes are unlocked.
The loop breaks.
If it fails (because one mutex is already locked by another thread):
It releases any partial lock.
The thread calls this_thread::yield() → 
gives CPU time to the other thread and retries.



fix
Fix with Lock Ordering

#include <iostream>
#include <thread>
#include <mutex>
using namespace std;

mutex mtx1, mtx2;

void safeTask1() 
{
    // Always lock in the same order: mtx1 → mtx2
    lock(mtx1, mtx2);
    lock_guard<mutex> lock1(mtx1, adopt_lock);
    lock_guard<mutex> lock2(mtx2, adopt_lock);
    cout << "Safe Task1 finished\n";
}

void safeTask2() 
{
    // Same lock order: mtx1 → mtx2
    lock(mtx1, mtx2);
    lock_guard<mutex> lock1(mtx1, adopt_lock);
    lock_guard<mutex> lock2(mtx2, adopt_lock);
    cout << "Safe Task2 finished\n";
}

int main() 
{
    thread t1(safeTask1);
    thread t2(safeTask2);

    t1.join();
    t2.join();
}

