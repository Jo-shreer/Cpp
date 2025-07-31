/*
Q2: Filesystem Metadata Cache Design
You’re tasked with designing a filesystem metadata cache to speed up operations like stat(), open(), and directory listings.

Requirements:
Cache metadata (file attributes, permissions, timestamps) 
for millions of files.
Support concurrent access by multiple threads/processes.

Metadata updates (like file modification time changes) must be 
consistent and visible to all readers.

Limit memory usage to avoid blowing up system resources.

Cache should handle cache misses by fetching metadata from disk efficiently.


Questions to answer:
What data structures would you use to implement the cache? Why?
How do you ensure thread-safe concurrent access and updates?
How do you handle cache invalidation when metadata changes on disk?
How would you manage memory usage for millions of entries?
How do you handle cache misses efficiently?
 */



#include <iostream>
#include <unordered_map>
#include <list>
#include <shared_mutex>
#include <string>

// Dummy Metadata struct for demonstration
struct Metadata {
    // Example metadata fields
    int size;
    int permissions;
    std::string modified_time;
    // Add more fields as needed
};

class MetadataCache {
public:
    MetadataCache(size_t capacity) : capacity_(capacity) {}

    Metadata get(const std::string& path) {
        {
            std::shared_lock<std::shared_mutex> readLock(mutex_);
            auto it = cache_.find(path);
            if (it != cache_.end()) {
                // Move accessed node to front (most recently used)
                promote(it);
                return it->second.first;
            }
        }
        // Cache miss: load from disk (simulate here)
        Metadata meta = loadFromDisk(path);

        // Insert into cache
        {
            std::unique_lock<std::shared_mutex> writeLock(mutex_);
            auto it = cache_.find(path);
            if (it == cache_.end()) {
                // Evict if necessary
                if (cache_.size() == capacity_) {
                    evictLRU();
                }
                // Insert new
                lruList_.push_front(path);
                cache_[path] = {meta, lruList_.begin()};
            } else {
                // Someone else inserted meanwhile, update & promote
                it->second.first = meta;
                promote(it);
            }
        }
        return meta;
    }

private:
    using ListIt = std::list<std::string>::iterator;

    void promote(std::unordered_map<std::string, std::pair<Metadata, ListIt>>::iterator it) {
        // Move node to front of the LRU list
        lruList_.erase(it->second.second);
        lruList_.push_front(it->first);
        it->second.second = lruList_.begin();
    }

    void evictLRU() {
        // Remove least recently used entry (back of list)
        const std::string& lruKey = lruList_.back();
        cache_.erase(lruKey);
        lruList_.pop_back();
    }

    Metadata loadFromDisk(const std::string& path) {
        // Simulate fetching metadata from disk with dummy data
        Metadata meta;
        meta.size = 100;  // Dummy values
        meta.permissions = 644;
        meta.modified_time = "2025-07-31 12:00:00";
        std::cout << "Loading metadata for " << path << " from disk\n";
        return meta;
    }

    size_t capacity_;
    std::unordered_map<std::string, std::pair<Metadata, ListIt>> cache_;
    std::list<std::string> lruList_;
    mutable std::shared_mutex mutex_;
};

int main() {
    MetadataCache cache(3);

    // Simulate accesses
    cache.get("/file1");
    cache.get("/file2");
    cache.get("/file3");
    cache.get("/file1"); // cache hit
    cache.get("/file4"); // evicts least recently used (file2)

    return 0;
}
