
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
detaching a thread means that the thread runs independently from the thread that launched it. 
The creator thread does not wait for the detached thread to finish.
It tells the system that the thread's resources should be automatically reclaimed once it finishes execution.
After calling detach(), you no longer have control over the thread — you can't join() it.
It allows the thread to execute in the background.

When to Use detach()
Use it when:
You truly want a thread to run in the background, e.g., logging, periodic monitoring, etc.
You don’t need to synchronize with the thread later.

Good Rule of Thumb:
If you start a thread, you must either join() or detach() it.
If you forget to do either, the destructor of the std::thread object will terminate the program (via std::terminate()).
*/

#include <iostream>
#include <thread>
#include <chrono>
using namespace std;

void backgroundTask() 
{
    cout << "Running in background..." << endl;
}

int main() 
{
    thread t(backgroundTask);
    t.detach(); // Let it run independently
    this_thread::sleep_for(chrono::seconds(1));
}


