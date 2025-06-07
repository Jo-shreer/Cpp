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
Insert({key, value}) - 	Adds a key-value pair. Duplicates are allowed.
find(key)	- Finds the first occurrence of the key.
equal_range(key) -	Returns a pair of iterators for the range of elements with a given key.
erase(key) - 	Removes all elements with the specified key.
erase(iterator) -	Removes the element pointed to by the iterator.

Use Cases for multimap:
Storing multiple values for the same key: For example, if you need to store a list of email addresses associated with each domain.
Maintaining sorted data: Since multimap keeps elements sorted by keys, it can be useful for applications where 
sorted key-value pairs are necessary (e.g., keeping track of students and their grades, where multiple students can have the same grade).

Multimap Usecase
1. Example: Storing Multiple Phone Numbers for a  single Person
In this example, we use a multimap to store multiple phone numbers associated with a person’s name (the key). 
The same person can have multiple phone numbers (e.g., home, work, mobile).

    multimap<string, string> phonebook;
    // Inserting multiple phone numbers for the same person
    phonebook.insert({"Alice", "123-456-7890"});
    phonebook.insert({"Alice", "987-654-3210"});
    phonebook.insert({"Bob", "555-123-4567"});
    phonebook.insert({"Bob", "555-987-6543"});
    phonebook.insert({"Charlie", "555-555-5555"});

2. Logging Events by Timestamp
   Imagine you are building an event logging system, and multiple events can happen at the same timestamp. 
   You could use a multimap to store the events, where the key is the timestamp, and the value is the event description.

   multimap<string, string> eventLog;
    // Inserting events with timestamps
    eventLog.insert({"2025-01-23 09:00", "System startup"});
    eventLog.insert({"2025-01-23 09:00", "User login"});
    eventLog.insert({"2025-01-23 09:05", "Data backup"});
    eventLog.insert({"2025-01-23 09:10", "System shutdown"});
    eventLog.insert({"2025-01-23 09:10", "User logout"});
  

Conclusion:
multimap -  
is useful when you need to store multiple values for the same key 
and need to maintain the order of elements.
unordered_map -  
on the other hand, provides faster lookups 
but does not allow duplicate keys and does not maintain any order for the elements.

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
