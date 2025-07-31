#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <queue>
using namespace std;

mutex mtx;
condition_variable not_empty;  // Wait when queue is empty
condition_variable not_full;   // Wait when queue is full

queue<int> q;
const unsigned int MAX_SIZE = 5;

void producer(int id) {
    for (int i = 0; i < 10; ++i) 
    {
        unique_lock<mutex> lock(mtx);
        not_full.wait(lock, []() { return q.size() < MAX_SIZE; });  // Wait if queue full

        q.push(i);
        cout << "Producer " << id << " produced " << i << endl;

        not_empty.notify_one();  // Notify consumer there's data
    }
}

void consumer(int id) 
{
    for (int i = 0; i < 10; ++i) 
    {
        unique_lock<mutex> lock(mtx);
        not_empty.wait(lock, []() { return !q.empty(); });  // Wait if queue empty

        int item = q.front();
        q.pop();
        cout << "Consumer " << id << " consumed " << item << endl;

        not_full.notify_one();  // Notify producer there's space
    }
}

int main() {
    thread p1(producer, 1);
    thread c1(consumer, 1);

    p1.join();
    c1.join();

    return 0;
}
