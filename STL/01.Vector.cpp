#include <iostream>
#include <vector>

int main() {
    // Create a vector of integers
    std::vector<int> numbers;

    // Adding elements to the vector
    numbers.push_back(10);
    numbers.push_back(20);
    numbers.push_back(30);

    // Displaying elements in the vector
    std::cout << "Vector elements: ";
    for (const int& num : numbers) {
        std::cout << num << " "; // Output: 10 20 30
    }
    std::cout << std::endl;

    // Accessing and modifying elements
    numbers[1] = 25; // Change the second element (20 to 25)

    std::cout << "After modification: ";
    for (const int& num : numbers) {
        std::cout << num << " "; // Output: 10 25 30
    }
    std::cout << std::endl;

    // Removing the last element
    numbers.pop_back(); // Remove the last element (30)

    std::cout << "After pop: ";
    for (const int& num : numbers) {
        std::cout << num << " "; // Output: 10 25
    }
    std::cout << std::endl;

    return 0;
}
