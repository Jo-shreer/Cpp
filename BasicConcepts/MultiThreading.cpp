
/*************************************Basic***********************/
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
