
/*
Q4. You’re asked to design a filesystem metadata cache. You need:
Fast lookups by file path.
Efficient eviction when cache is full.
What data structure(s) would you choose and why?

*/

#include <iostream>
#include <unordered_map>
#include <list>
#include <string>
using namespace std;

struct Metadata 
{
    int inode;
    string permissions;
    string timestamp;
    // can add more fields as needed
};

class MetadataCache 
{
    int capacity;
    list<pair<string, Metadata>> lruList; // {path, metadata}
    unordered_map<string, list<pair<string, Metadata>>::iterator> cache;

    public:
    MetadataCache(int cap) : capacity(cap) {}

    Metadata* get(const string& path) 
    {
        auto it = cache.find(path);
        if (it == cache.end()) 
        {
            cout << "Cache miss for " << path << endl;
            return nullptr;
        }
        // Move accessed node to front (MRU)
        lruList.splice(lruList.begin(), lruList, it->second);
        return &it->second->second;
    }

    void put(const string& path, const Metadata& meta) 
    {
        auto it = cache.find(path);

        if (it != cache.end()) 
        {
            // Update existing entry, move to front
            it->second->second = meta;
            lruList.splice(lruList.begin(), lruList, it->second);
        } 
        else 
        {
            // Evict if full
            if ((int)lruList.size() == capacity) 
            {
                auto last = lruList.back();
                cache.erase(last.first);
                lruList.pop_back();
            }
            // Insert new entry at front
            lruList.emplace_front(path, meta);
            cache[path] = lruList.begin();
        }
    }
};

// Example usage
int main() 
{
    MetadataCache cache(2);

    cache.put("/file1", {1, "rw-r--r--", "2025-07-31"});
    cache.put("/file2", {2, "rwxr-xr-x", "2025-07-30"});

    // Access file1 (becomes most recently used)
    auto meta = cache.get("/file1");
    if (meta) cout << "Accessed inode: " << meta->inode << endl;

    // Insert file3 → evicts least recently used (file2)
    cache.put("/file3", {3, "rw-------", "2025-07-29"});

    if (!cache.get("/file2")) cout << "File2 evicted!" << endl;

    return 0;
}
