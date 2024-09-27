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
