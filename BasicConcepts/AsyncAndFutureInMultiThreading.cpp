/*
std::async runs a function asynchronously (potentially in a new thread), and returns a std::future object, which you can use to get the result of that function once it completes.
*/

#include <iostream>
#include <future>
#include <chrono>
using namespace std;

int slow_add(int a, int b) 
{
    this_thread::sleep_for(chrono::seconds(2));  // Simulate work
    return a + b;
}

int main() 
{
    cout << "Launching async task...\n";
  
    // Launch async task
    future<int> result = async(slow_add, 5, 7);
  
    cout << "Doing other work while waiting...\n";

    // Block until result is ready, then get it
    int sum = result.get();
    cout << "Result from async: " << sum << endl;

    return 0;
}

/*output*/
Launching async task...
Doing other work while waiting...
Result from async: 12

