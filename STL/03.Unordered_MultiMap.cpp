/*
unordered_multimap 
1. Duplicates Key allowed - It allows multiple elements with the same key.
2. Elements are stored in buckets using a hash function, so no particular order is guaranteed.
3. Provides fast average O(1) time complexity for insertion, lookup, and deletion.
4. Internally implemented as a hash table
5. It is an unordered associative container that stores key-value pairs.
*/

#include <iostream>
#include <unordered_map>
using namespace std;

int main() 
{
    unordered_multimap<string, int> umm;
    // Insert key-value pairs (duplicates allowed)
    umm.insert({"apple", 100});
    umm.insert({"banana", 200});
    umm.insert({"apple", 150});
    umm.insert({"orange", 300});
    umm.insert({"banana", 250});

    for (const auto& kv : umm) 
    {
        cout << kv.first << " => " << kv.second << "\n";
    }

    // Count how many elements with key "apple"
    cout << "Count of 'apple': " << umm.count("apple") << "\n";

    // Find and print all values with key "banana"
    auto range = umm.equal_range("banana");
    cout << "Values for 'banana': ";
    for (auto it = range.first; it != range.second; ++it) 
    {
        cout << it->second << " ";
    }
    cout << "\n";

    return 0;
}

o/p
banana => 250
orange => 300
apple => 150
banana => 200
apple => 100
Count of 'apple': 2
Values for 'banana': 250 200 
