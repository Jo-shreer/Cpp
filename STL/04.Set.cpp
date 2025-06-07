/*
set 
1. stores unique elements.
2. Elements are stored in sorted order (by default using operator<).
3. Implemented as a balanced binary search tree (usually a Red-Black tree).
4. Provides efficient lookup, insertion, and removal with O(log n) time complexity.
5. associative container.
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
