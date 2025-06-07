/*
Multiset 
1. It allows duplicate elements.
2. Stores multiple elements in sorted order.
3. Implemented as a balanced binary search tree (usually a Red-Black tree).
4. Provides efficient lookup, insertion, and removal with O(log n) complexity.
5. Associative container.
*/ 

#include <iostream>
#include <set>

int main() {
    // Create a multiset of integers
    std::multiset<int> myMultiSet;

    // Adding elements (including duplicates)
    myMultiSet.insert(10);
    myMultiSet.insert(20);
    myMultiSet.insert(20); // Duplicate, will be allowed
    myMultiSet.insert(30);

    // Displaying elements
    std::cout << "Multiset elements: ";
    for (const int& num : myMultiSet) {
        std::cout << num << " "; // Output: 10 20 20 30
    }
    std::cout << std::endl;

    // Counting occurrences of an element
    std::cout << "Count of 20: " << myMultiSet.count(20) << std::endl; // Output: 2

    // Removing an element
    myMultiSet.erase(20); // Remove one instance of 20

    std::cout << "After removing one 20: ";
    for (const int& num : myMultiSet) {
        std::cout << num << " "; // Output: 10 20 30
    }
    std::cout << std::endl;

    return 0;
}
