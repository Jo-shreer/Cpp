/*
list 
Allows fast insertion and deletion of elements anywhere in the list (constant time).
Does not support random access (no operator[]).
Iteration is bidirectional using bidirectional iterators.
Useful when frequent insertions/deletions in the middle of the sequence are needed.
is a sequence container that implements a doubly linked list.
Access element by iterator	        O(1)	Dereferencing iterator is constant time
Access element by position (index)	O(n)	Must traverse from start or end
Insertion at beginning (push_front)	O(1)	Constant time
Insertion at end (push_back)	    O(1)	Constant time
Deletion at beginning (pop_front)	O(1)	Constant time
Deletion at end (pop_back)	        O(1)	Constant time
Deletion at iterator (erase)	    O(1)	Constant time if iterator is known
Size (size())	                    O(1)	Since C++11, size is cached
Search for value (find or remove)	O(n)	Linear time since no random access
*/

#include <iostream>
#include <list>

int main() {
    // Create a list of integers
    std::list<int> myList;

    // Adding elements
    myList.push_back(10);
    myList.push_back(20);
    myList.push_back(30);

    // Displaying elements
    std::cout << "List elements: ";
    for (const int& num : myList) {
        std::cout << num << " "; // Output: 10 20 30
    }
    std::cout << std::endl;

    // Inserting elements
    myList.insert(++myList.begin(), 15); // Insert 15 between 10 and 20

    std::cout << "After insertion: ";
    for (const int& num : myList) {
        std::cout << num << " "; // Output: 10 15 20 30
    }
    std::cout << std::endl;

    // Removing elements
    myList.remove(20); // Remove element 20

    std::cout << "After removal: ";
    for (const int& num : myList) {
        std::cout << num << " "; // Output: 10 15 30
    }
    std::cout << std::endl;

    return 0;
}
