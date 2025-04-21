
/*************************************Creation of thread***********************/
#include <iostream>
#include <thread>

using namespace std;

void printMessage(const string& msg) 
{
    cout << "Message from thread: " << msg << endl;
}

int main() 
{
    thread t1(printMessage, "Hello from t1!");
    thread t2(printMessage, "Hello from t2!");

    t1.join(); // Wait for t1 to finish
    t2.join(); // Wait for t2 to finish

    cout << "Main thread ends." << endl;
    return 0;
}

/************************************Passing an argument***********************/

#include <iostream>
#include <thread>

using namespace std;

void printNumber(int x) 
{
    cout << "Number: " << x << endl;
}

int main() {
    thread t(printNumber, 42);
    t.join();
}


/***********************************Using Lambda with Threads***********************/
#include <iostream>
#include <thread>

using namespace std;

int main() {
    thread t([]() {
        cout << "Hello from lambda thread!" << endl;
    });
    t.join();
}

/***********************************DetachThreads***********************/
/*What does detach() do?
It tells the system that the thread's resources should be automatically reclaimed once it finishes execution.

After calling detach(), you no longer have control over the thread — you can't join() it.

It allows the thread to execute in the background.*/

#include <iostream>
#include <thread>
#include <chrono>
using namespace std;

void backgroundTask() 
{
    cout << "Running in background..." << endl;
}

int main() {
    thread t(backgroundTask);
    t.detach(); // Let it run independently
    this_thread::sleep_for(chrono::seconds(1));
}



