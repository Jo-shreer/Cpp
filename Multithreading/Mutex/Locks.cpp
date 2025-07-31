#include <iostream>
#include <thread>
#include <mutex>
#include <shared_mutex>
#include <chrono>
using namespace std;

// 1. std::mutex with manual lock/unlock
// You manually lock and unlock the mutex. 

If you forget to unlock, it causes deadlocks.
  
mutex mtx1;
int counter1 = 0;
void incrementManual() 
{
    for (int i = 0; i < 5; i++) 
    {
        mtx1.lock();                    // Lock mutex before accessing shared data
        counter1++;
        cout << "Manual Lock Counter: " << counter1 << endl;
        mtx1.unlock();                  // Unlock mutex after done
    }
}

// 2. std::lock_guard (RAII locking)
// Automatically locks on creation and unlocks when it goes out of scope.
// Safer and cleaner than manual lock/unlock.

mutex mtx2;
int counter2 = 0;
void incrementLockGuard() 
{
    for (int i = 0; i < 5; i++) 
    {
        lock_guard<mutex> lock(mtx2);  // Lock mutex automatically here
        counter2++;
        cout << "Lock Guard Counter: " << counter2 << endl;
        // Unlock happens automatically when 'lock' goes out of scope
    }
}

// 3. std::unique_lock (flexible RAII lock)
// Like lock_guard, but you can manually unlock or relock inside the scope.
// Useful for advanced locking scenarios.

mutex mtx3;
int counter3 = 0;
void incrementUniqueLock() 
{
    for (int i = 0; i < 5; i++) 
    {
        unique_lock<mutex> lock(mtx3); // Lock mutex
        counter3++;
        cout << "Unique Lock Counter: " << counter3 << endl;
        lock.unlock();                 // Manually unlock early if needed
        // Do some other work without the lock here
    }
}

// 4. std::recursive_mutex (recursive locking)
// Allows the same thread to lock multiple times safely (recursive functions).

recursive_mutex rmtx;
void recursiveFunction(int count) 
{
    if (count <= 0) return;
    rmtx.lock();                       // Lock mutex (recursive locks allowed)
    cout << "Recursive count: " << count << endl;
    recursiveFunction(count - 1);
    rmtx.unlock();                     // Unlock mutex
}

// 5. std::timed_mutex (try lock with timeout)
// Attempts to lock mutex, but gives up if timeout expires to
//avoid blocking forever.

timed_mutex tmtx;
void tryLockFunc() 
{
    if (tmtx.try_lock_for(chrono::milliseconds(100))) 
    { // Try locking for max 100ms
        cout << "Timed mutex: Lock acquired\n";
        this_thread::sleep_for(chrono::milliseconds(200)); // Hold lock for a bit
        tmtx.unlock();
    } else 
    {
        cout << "Timed mutex: Failed to acquire lock\n";   // Timeout expired
    }
}

// 6. std::shared_mutex and std::shared_lock (reader-writer lock)
// Allows multiple concurrent readers but only one writer exclusively.

shared_mutex smtx;
int sharedData = 0;

void reader(int id) 
{
    shared_lock<shared_mutex> lock(smtx);  // Shared lock (multiple readers allowed)
    cout << "Reader " << id << " read data = " << sharedData << endl;
    this_thread::sleep_for(chrono::milliseconds(50));
}

void writer() 
{
    unique_lock<shared_mutex> lock(smtx);  // Exclusive lock for writing
    sharedData++;
    cout << "Writer updated data to " << sharedData << endl;
    this_thread::sleep_for(chrono::milliseconds(100));
}

int main() 
{
    cout << "--- std::mutex manual lock/unlock ---\n";
    thread t1(incrementManual);
    thread t2(incrementManual);
    t1.join();
    t2.join();

    cout << "\n--- std::lock_guard (RAII) ---\n";
    thread t3(incrementLockGuard);
    thread t4(incrementLockGuard);
    t3.join();
    t4.join();

    cout << "\n--- std::unique_lock (flexible) ---\n";
    thread t5(incrementUniqueLock);
    thread t6(incrementUniqueLock);
    t5.join();
    t6.join();

    cout << "\n--- std::recursive_mutex ---\n";
    thread t7(recursiveFunction, 3);
    t7.join();

    cout << "\n--- std::timed_mutex ---\n";
    thread t8(tryLockFunc);
    this_thread::sleep_for(chrono::milliseconds(50));  // Delay to create contention
    thread t9(tryLockFunc);
    t8.join();
    t9.join();

    cout << "\n--- std::shared_mutex and std::shared_lock ---\n";
    thread r1(reader, 1);
    thread r2(reader, 2);
    thread w(writer);
    r1.join();
    r2.join();
    w.join();

    return 0;
}
