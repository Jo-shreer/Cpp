#include <iostream>
#include <atomic>
#include <thread>

using namespace std;

atomic<int> atomicInt(0);

void writer() 
{
    for (int i = 1; i <= 5; ++i) 
    {
        atomicInt.store(i);  // Atomically update the value
        cout << "Writer updated value to " << i << endl;
        this_thread::sleep_for(chrono::milliseconds(100));
    }
}

void reader() 
{
    for (int i = 0; i < 5; ++i) 
    {
        int val = atomic_load(&atomicInt);  // Atomically read the value
        cout << "Reader read value: " << val << endl;
        this_thread::sleep_for(chrono::milliseconds(150));
    }
}

int main() 
{
    thread t1(writer);
    thread t2(reader);

    t1.join();
    t2.join();

    return 0;
}


Writer updated value to 1
Reader read value: 1
Writer updated value to 2
Reader read value: 2
Writer updated value to 3
Reader read value: 3
Writer updated value to 4
Reader read value: 4
Writer updated value to 5
Reader read value: 5
  
