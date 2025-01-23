/*A multimap in C++ is an associative container that stores key-value pairs. 
The key feature of a multimap is that it allows multiple elements to have the same key. 
This makes it different from a map, which stores only unique keys. 
In a multimap, each key can map to one or more values, and the elements are always stored in sorted order based on the keys.

Key Characteristics of multimap:
Allows Duplicate Keys: A multimap allows multiple pairs with the same key, unlike a map where keys are unique.
Ordered by Keys: The elements are sorted by their keys using the comparison function (default is operator<).
Fast Search: The underlying data structure is usually a balanced binary search tree (Red-Black Tree), 
ensuring logarithmic time complexity for operations like insertion, deletion, and search.
Associative Container: Like other associative containers, you access elements by keys, not by index.

Key Methods
insert({key, value}): Inserts a new key-value pair into the multimap. 
                      If the key already exists, the new value is added alongside the existing values for that key.
find(key): Searches for the first occurrence of a key. Returns an iterator pointing to the element or end() if the key is not found.
equal_range(key): Returns a pair of iterators representing the range of elements with the specified key. 
                  This is particularly useful when you want to process all values associated with a key.
erase(key): Removes all elements with the specified key. If you want to remove a specific element by iterator,
            you can pass an iterator to erase().
*/

#include <iostream>
#include <map>
using namespace std;

int main() 
{
    // Creating a multimap of int -> string
    multimap<int, string> mm;
    
    // Inserting elements into the multimap
    mm.insert({1, "apple"});   //You can insert elements using insert() or emplace() methods.
    mm.insert({1, "banana"});
    mm.insert({2, "cherry"});
    mm.insert({3, "date"});
    mm.insert({2, "elderberry"});
    
    // Iterating and displaying the elements in sorted order of keys
    for (const auto& pair : mm) 
    {
        cout << pair.first << ": " << pair.second << endl;
    }

    return 0;
}
