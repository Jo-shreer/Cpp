#include <iostream>
#include <thread>
#include <vector>
#include <chrono>
using namespace std;

class BoundedQueue 
{
    public:
    explicit BoundedQueue(int capacity) : capacity_(capacity) {}

    void enqueue(int item) 
    {
        unique_lock<mutex> lock(mtx);
        cv.wait(lock, [this]() { return q.size() < capacity_; });
        q.push(item);
        not_empty.notify_one();
    }

    int dequeue() {
        unique_lock<mutex> lock(mtx);
        not_empty.wait(lock, 
        [this]() 
        { 
          return !q.empty(); 
        });
      
        int item = q.front();
        q.pop();
        cv.notify_one();
        return item;
    }

    private:
    int capacity_;
    queue<int> q;
    mutex mtx;
    condition_variable not_full;
    condition_variable not_empty;
};

void producer(BoundedQueue& bq, int count) 
{
    for (int i = 0; i < count; ++i) 
    {
        bq.enqueue(i);
        cout << "Produced: " << i << endl;
        this_thread::sleep_for(chrono::milliseconds(100));
    }
}

void consumer(BoundedQueue& bq, int id, int count) 
{
    for (int i = 0; i < count; ++i) {
        int item = bq.dequeue();
        cout << "Consumer " << id << " consumed: " << item << endl;
        this_thread::sleep_for(chrono::milliseconds(150));
    }
}

int main() 
{
    BoundedQueue bq(5);
    const int total_items = 20;
    const int consumer_count = 3;

    thread prod(producer, ref(bq), total_items);
  
    vector<thread> consumers;
    int items_per_consumer = total_items / consumer_count;

    for (int i = 0; i < consumer_count; ++i) 
    {
        consumers.emplace_back(consumer, ref(bq), i + 1, items_per_consumer);
    }
    prod.join();
    for (auto& c : consumers) 
    {
        c.join();
    }

    return 0;
}
