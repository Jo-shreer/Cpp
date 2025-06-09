/*
set 
1. stores unique elements.
2. Elements are stored in sorted order (by default using operator<).
3. Implemented as a balanced binary search tree (usually a Red-Black tree).
4. Provides efficient lookup, insertion, and removal with O(log n) time complexity.
5. associative container.

std::set Member Functions
Function	Description
Constructors & Destructor	
set()	Default constructor
set(const set&)	Copy constructor
set(set&&)	Move constructor
~set()	Destructor
Assignment	
operator=(const set&)	Copy assignment
operator=(set&&)	Move assignment

Iterators	
begin()	Returns iterator to first element
end()	Returns iterator to past-the-end element
cbegin()	Returns const iterator to first element
cend()	Returns const iterator to past-the-end element
rbegin()	Returns reverse iterator to last element
rend()	Returns reverse iterator to before first element

Capacity	
empty()	Checks if container is empty
size()	Returns number of elements
max_size()	Returns maximum possible size

Modifiers	
insert(const value_type&)	Inserts element
insert(value_type&&)	Inserts element (move version)
insert(InputIt first, InputIt last)	Inserts elements from range
emplace(args...)	    Constructs and inserts element
erase(iterator pos)	    Erases element at iterator
erase(const key_type&)	Erases elements with given key
erase(iterator first, iterator last)	Erases elements in range

Lookup	
find(const key_type&)	        Finds element with key
count(const key_type&)	        Counts elements with key (0 or 1 for set)
lower_bound(const key_type&)	Returns iterator to first element ≥ key
upper_bound(const key_type&)	Returns iterator to first element > key
equal_range(const key_type&)	Returns pair of iterators for range of equal keys (at most one for set)
Observers	
key_comp()	Returns key comparison function
value_comp()	Returns value comparison function (same as key_comp for set)

*/    
#include <iostream>
#include <set>

int main() {
    // Create a set of integers
    std::set<int> mySet;

    // Adding elements
    mySet.insert(10);
    mySet.insert(20);
    mySet.insert(30);
    mySet.insert(20); // Duplicate, will be ignored

    // Displaying elements
    std::cout << "Set elements: ";
    for (const int& num : mySet) {
        std::cout << num << " "; // Output: 10 20 30
    }
    std::cout << std::endl;

    // Checking if an element exists
    if (mySet.find(20) != mySet.end()) {
        std::cout << "20 is in the set." << std::endl;
    } else {
        std::cout << "20 is not in the set." << std::endl;
    }

    // Removing an element
    mySet.erase(10); // Remove element 10

    std::cout << "After removal: ";
    for (const int& num : mySet) {
        std::cout << num << " "; // Output: 20 30
    }
    std::cout << std::endl;

    return 0;
}
