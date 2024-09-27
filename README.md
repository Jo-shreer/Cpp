# STL
- [vector](vector)
- [list](list)
- [list](list)
- [list](list)



# list
 list is part of the Standard Template Library (STL) and represents a doubly linked list. It allows for efficient insertion and removal of elements from any position, but accessing elements by index is less 
 efficient compared to vectors.

 ```cpp
#include <list>

std::list<int> numbers; // A list of integers
std::list<std::string> names; // A list of strings
std::list<int> numbers(5, 0); // A list of 5 integers, all initialized to 0
numbers.push_back(10); // Add to the end
numbers.push_front(5); // Add to the front

numbers.pop_back(); // Removes the last element
numbers.pop_front(); // Removes the first element
numbers.remove(10); // Removes all occurrences of 10
```
### example 
```cpp
#include <iostream>
#include <list>

int main() {
    std::list<int> numbers;

    // Adding elements
    numbers.push_back(10);
    numbers.push_back(20);
    numbers.push_front(5);

    // Iterating over the list
    std::cout << "Numbers: ";
    for (int number : numbers) {
        std::cout << number << " ";
    }
    std::cout << std::endl;

    // Removing an element
    numbers.remove(10);

    std::cout << "After removing 10, numbers: ";
    for (int number : numbers) {
        std::cout << number << " ";
    }
    std::cout << std::endl;

    return 0;
}
```
### Note
Lists are useful when you need frequent insertions and deletions from anywhere in the container.
However, if you need to access elements by index frequently, consider using vectors instead, as they provide better performance for random access.
______________________________________________________________________________________________________________________________________________________________________________________________________________
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
```cpp
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
```
______________________________________________________________________________________________________________________________________________________________________________________________________________

