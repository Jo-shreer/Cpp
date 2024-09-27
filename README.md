# STL
-[vector](vector)




# Vector
 vector is part of the Standard Template Library (STL) and provides a dynamic array that can grow and shrink in size. 
 It allows you to store elements and provides many useful member functions to manipulate the data.

```cpp
#include <vector>
std::vector<int> numbers; // A vector of integers
std::vector<double> prices; // A vector of doubles
std::vector<std::string> names; // A vector of strings

std::vector<int> numbers(10, 0); // A vector of 10 integers, all initialized to 0
```
### Adding elements
```cpp
numbers.push_back(1);
numbers.push_back(2);
int first = numbers[0];      // accessing elements using []
int second = numbers.at(1);  // Using at()
```
### Example Code
#include <iostream>
#include <vector>

int main() {
    std::vector<int> numbers;

    // Adding elements
    numbers.push_back(10);
    numbers.push_back(20);
    numbers.push_back(30);

    // Accessing elements
    std::cout << "First number: " << numbers[0] << std::endl;

    // Iterating over the vector
    std::cout << "All numbers: ";
    for (int number : numbers) {
        std::cout << number << " ";
    }
    std::cout << std::endl;

    // Removing the last element
    numbers.pop_back();

    std::cout << "After popping back, numbers: ";
    for (int number : numbers) {
        std::cout << number << " ";
    }
    std::cout << std::endl;
    return 0;
}

