/*
When an application writes 4KB to a file,
what happens inside the OS and storage stack?”

*/


#include <iostream>
#include <unordered_map>
#include <thread>
#include <chrono>
#include <mutex>
#include <condition_variable>

using namespace std;

class PageCache {
private:
    struct Entry {
        string data;
        bool dirty;
    };

    unordered_map<int, Entry> cache;
    mutex mtx;
    condition_variable cv;

    void flushPage(int id, const string& data) {
        // simulate disk write
        cout << "[FLUSH] Writing page " << id << " to disk: " << data << "\n";
    }

public:
    void write(int pageId, const string& data) {
        unique_lock<mutex> lock(mtx);
        cache[pageId] = {data, true};  // mark dirty
        cout << "[WRITE] Page " << pageId << " updated, marked dirty\n";
        cv.notify_one();
    }

    void fsync(int pageId) {
        unique_lock<mutex> lock(mtx);
        auto it = cache.find(pageId);
        if (it != cache.end() && it->second.dirty) {
            flushPage(it->first, it->second.data);
            it->second.dirty = false;
        }
    }

    // background flusher thread
    void flusher() {
        while (true) {
            unique_lock<mutex> lock(mtx);
            cv.wait_for(lock, chrono::seconds(2)); // wake periodically
            for (auto& [id, entry] : cache) {
                if (entry.dirty) {
                    flushPage(id, entry.data);
                    entry.dirty = false;
                }
            }
        }
    }
};

int main() {
    PageCache pc;

    // start flusher in background
    thread t(&PageCache::flusher, &pc);

    pc.write(1, "Hello");
    pc.write(2, "World");

    this_thread::sleep_for(chrono::seconds(1));

    // explicitly fsync page 1
    pc.fsync(1);

    this_thread::sleep_for(chrono::seconds(5));

    t.detach();
    return 0;
}
