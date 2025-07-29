#include <iostream>
#include <queue>
#include <mutex>
#include <thread>
#include <condition_variable>
using namespace std;

queue<string> messageQueue;
mutex mutexQueue;
condition_variable cv;

void producer() 
{
    for (int i = 0; i < 5; ++i) 
    {
        string message = "Message " + to_string(i);
        {
            lock_guard<mutex> lock(mutexQueue);
            messageQueue.push(message);
        }
        cv.notify_one(); // Notify the consumer that a new message is available
        this_thread::sleep_for(chrono::seconds(1));
    }
}

void consumer() 
{
    while (true) 
    {
        unique_lock<mutex> lock(mutexQueue);
        cv.wait(lock, [] 
        {
            return !messageQueue.empty(); 
            
        });
        string message = messageQueue.front();
        messageQueue.pop();
        lock.unlock();
        
        cout << "Received: " << message << endl;
        // Process the message
        this_thread::sleep_for(chrono::milliseconds(500));
    }
}

int main() 
{
    thread producerThread(producer);
    thread consumerThread(consumer);

    producerThread.join();
    consumerThread.join();

    return 0;
}
