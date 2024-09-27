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
