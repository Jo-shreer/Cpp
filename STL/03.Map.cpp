/* 
1. duplicate keys are not allowed.
2. Elements are stored sorted by key (default sorting uses operator<).
3. Implemented as a balanced binary search tree (usually a Red-Black tree).
4. Supports efficient lookup, insertion, and deletion with O(log n) complexity.
5. map is an associative container storing key-value pairs.
*/

#include <iostream>
#include <map>

int main() {
    // Create a map of integers (key) to strings (value)
    std::map<int, std::string> myMap;

    // Adding elements
    myMap[1] = "One";
    myMap[2] = "Two";
    myMap[3] = "Three";

    // Displaying elements
    std::cout << "Map elements:" << std::endl;
    for (const auto& pair : myMap) {
        std::cout << pair.first << ": " << pair.second << std::endl; // Output: key: value
    }

    // Accessing elements
    std::cout << "Value for key 2: " << myMap.at(2) << std::endl; // Output: Two

    // Updating an element
    myMap[2] = "Deux"; // Change "Two" to "Deux"

    std::cout << "Updated value for key 2: " << myMap.at(2) << std::endl; // Output: Deux

    // Removing an element
    myMap.erase(1); // Remove element with key 1

    std::cout << "After removal:" << std::endl;
    for (const auto& pair : myMap) {
        std::cout << pair.first << ": " << pair.second << std::endl; // Output: Remaining elements
    }

    return 0;
}
