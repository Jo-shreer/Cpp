/*
Question:
Explain how you would implement a high-performance, thread-safe logging system.
How would you handle concurrent writes from multiple threads?
How do you minimize performance overhead?
Would you use buffering? How and when would logs be flushed to disk?

*/


#include <iostream>
#include <fstream>
#include <string>
#include <mutex>
#include <thread>
#include <chrono>

class Logger 
{
    std::timed_mutex mtx;
    std::ofstream logfile;

    public:
    Logger(const std::string& filename) : logfile(filename, std::ios::app) {}

    void log(const std::string& message) 
     {
        if (mtx.try_lock_for(std::chrono::milliseconds(100))) 
        {
            logfile << message << std::endl;
            mtx.unlock();
        } 
        else 
        {
            // Could not acquire lock quickly, drop or buffer log
            std::cerr << "Log dropped: " << message << std::endl;
        }
    }
};
