/*
LRU Cache Implementation Approach
Use an unordered_map (hash map) to map keys to nodes for O(1) lookup.

Use a doubly linked list to store the usage order:
Front = most recently used
Back = least recently used
On get(key):
If key exists, move the corresponding node to the front (marking it most recently used).
On put(key, value):
If key exists, update value and move node to front.
Else, insert new node at front.
If capacity exceeded, remove node from the back (least recently used).

*/


#include <iostream>
#include <unordered_map>
#include <list>
using namespace std;

class LRUCache 
{
    int capacity;
    list<pair<int, int>> dll; // key-value pairs, front = most recent
    unordered_map<int, list<pair<int, int>>::iterator> mp; // key to list iterator

    public:
    LRUCache(int cap) : capacity(cap) {}

    int get(int key) 
     {
        if (mp.find(key) == mp.end()) return -1; // not found

        // Move accessed node to front
        auto it = mp[key];
        int val = it->second;
        dll.erase(it);
        dll.push_front({key, val});
        mp[key] = dll.begin();
        return val;
    }

    void put(int key, int value) 
    {
        if (mp.find(key) != mp.end()) 
        {
            // Remove old node
            dll.erase(mp[key]);
        } 
        else if ((int)dll.size() == capacity) 
        {
            // Remove least recently used from back
            auto last = dll.back();
            mp.erase(last.first);
            dll.pop_back();
        }
        // Insert new node at front
        dll.push_front({key, value});
        mp[key] = dll.begin();
    }
};

int main() 
{
    LRUCache cache(2); // capacity 2

    cache.put(1, 10);
    cache.put(2, 20);
    cout << cache.get(1) << endl;   // returns 10
    cache.put(3, 30);                // evicts key 2
    cout << cache.get(2) << endl;   // returns -1 (not found)
    cache.put(4, 40);                // evicts key 1
    cout << cache.get(1) << endl;   // returns -1 (not found)
    cout << cache.get(3) << endl;   // returns 30
    cout << cache.get(4) << endl;   // returns 40

    return 0;
}

