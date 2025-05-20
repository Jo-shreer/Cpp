/*A condition variable is a synchronization primitive that allows threads to wait (block) until notified by another thread 
that some condition is true. It helps when one thread depends on another to complete a task or update shared data.
Why Use a Condition Variable?

Imagine a producer-consumer scenario:
The producer adds data to a buffer.
The consumer waits until there's data in the buffer before processing it.
Without a condition variable, the consumer would need to poll the buffer constantly.
With a condition variable, it can just wait efficiently.

Syntax & Components (in namespace std)
std::mutex: Protects shared data.
std::condition_variable: The condition variable itself.
std::unique_lock<std::mutex>: Works with the condition variable.
cv.wait(lock, predicate): Waits until the predicate is true.
cv.notify_one() or cv.notify_all(): Wakes up one/all waiting threads.
*/

#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <queue>
using namespace std;

queue<int> buffer;
const unsigned int maxBufferSize = 5;
mutex mtx;
condition_variable cv;

void producer() 
{
    int value = 0;
    while (true) 
    {
        unique_lock<mutex> lock(mtx);
        cv.wait(lock, []() { return buffer.size() < maxBufferSize; });
        buffer.push(value);
        cout << "Produced: " << value << endl;
        value++;
        lock.unlock();
        cv.notify_all();  // Wake up consumers
        this_thread::sleep_for(chrono::milliseconds(500));
    }
}

void consumer() {
    while (true) {
        unique_lock<mutex> lock(mtx);
        cv.wait(lock, []() { return !buffer.empty(); });

        int item = buffer.front();
        buffer.pop();
        cout << "Consumed: " << item << endl;

        lock.unlock();
        cv.notify_all();  // Wake up producers
        this_thread::sleep_for(chrono::milliseconds(1000));
    }
}

int main() 
{
    thread t1(producer);
    thread t2(consumer);
    t1.join();
    t2.join();
    return 0;
}
