/*In C++, an unordered_map is a standard library container that stores key-value pairs. 
Unlike a map, which stores keys in a sorted order, an unordered_map stores keys in an unsorted order, and it provides 
average constant-time complexity (O(1)) for lookups, insertions, and deletions. It is implemented using hash tables internally.

Important Points:

Return Value:
insert() returns a pair<iterator, bool>. The iterator points to the inserted element (or the existing one), 
and the bool indicates whether the insertion was successful.

No Replacement:
insert() does not replace existing values. If the key already exists in the map, the map remains unchanged.

Time Complexity:
The average time complexity for insert() is O(1) for each insertion (on average), because unordered_map uses 
hash tables to store the elements.

Avoiding Duplicate Keys:
If you want to replace an existing value, you should use the [] operator or emplace(), as they allow updates to existing keys.

Feature                                map	                                  unordered_map
Ordering	                       Sorted (according to the key)	        Unordered (based on hash values)
Underlying Data Structure	       Balanced Binary Tree (Red-Black Tree).	 Hash Table
Time Complexity	                       O(log n) for insert, find, delete.    	O(1) on average for insert, find, delete
Best Use Case	                      When order of keys matters.                When order doesn't matter, and fast lookups are needed.
Memory Overhead	                      Higher due to tree structure.        	  Lower,but hash table can cause rehashing and 
                                                                                memory overhead
Iteration	                      Iterates in sorted order.            	Iterates in undefined order
Custom Sorting	                     Custom comparison function allowed	    Custom hash function allowed

*/

#include <iostream>
#include <unordered_map>
using namespace std;

int main() 
{
    unordered_map<int, string> umap;  // Declaring an unordered_map with int as key and string as value
    umap[1] = "apple";  // Inserting key-value pairs
    umap[2] = "banana";
    umap[3] = "cherry";

    OR
    umap.insert({"apple", 5});
    umap.insert({"banana", 3});
    umap.insert({"orange", 7});
    
    // Accessing elements using keys
    cout << "Key 1: " << umap[1] << endl; // You can insert elements using the [] operator or the insert() function.
    cout << "Key 2: " << umap[2] << endl;
    
    // Iterating through an unordered_map
    for (const auto& pair : umap) 
    {
        cout << pair.first << ": " << pair.second << endl;
    }
    return 0;
}

