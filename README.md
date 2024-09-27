# STL
- [vector](#vector)
- [list](#list)
- [map](#map)
- [set](#set)
- [multimap](#multimap)
- [multiset](#multiset)

# multiset
A multiset is an associative container in C++ that stores elements in a sorted order while allowing multiple occurrences of the same element. 
This makes it different from a regular set, which only allows unique elements.

### Key Features of Multiset:
Multiple Elements: A multiset can contain multiple instances of the same element.
Ordered Storage: Elements are stored in sorted order, allowing for efficient retrieval and iteration.
Automatic Sorting: When elements are inserted, they are automatically placed in the correct order.

### syntax
```cpp
std::multiset<int> ms; // Declare a multiset to store integers

// Inserting elements into the multiset, allowing duplicates
ms.insert(5);
ms.insert(1);
ms.insert(5); // Duplicate element
ms.insert(3);
ms.insert(2);

// Erase all occurrences of the element '1' from the multiset
ms.erase(1);
```
# example
```cpp
#include <iostream> // For input/output operations
#include <set>      // For using std::multiset

int main() {
    // Declare a multiset to store integers
    std::multiset<int> ms;

    // Insert elements into the multiset, allowing duplicates
    ms.insert(5);
    ms.insert(1);
    ms.insert(5); // Duplicate element
    ms.insert(3);
    ms.insert(2);

    // Display elements in sorted order
    std::cout << "Multiset elements:\n";
    for (const auto& elem : ms) {
        std::cout << elem << " "; // Print each element
    }
    std::cout << "\n"; // New line after displaying elements

    // Count occurrences of a specific element
    int key = 5; // Element to count
    std::cout << "Count of " << key << ": " << ms.count(key) << "\n";

    // Erase all occurrences of the element '1' from the multiset
    ms.erase(1); 
    std::cout << "Elements after erasing 1:\n";
    // Display remaining elements
    for (const auto& elem : ms) {
        std::cout << elem << " "; // Print each element
    }
    std::cout << "\n"; // New line after displaying elements

    return 0; // Indicate successful completion
}
```


### conclusion
A multiset is a useful container in C++ when you need to maintain a collection of elements that allows duplicates and requires ordered storage. 
Its automatic sorting and efficient retrieval make it suitable for various applications where the frequency of elements matters.
____________________________________________________________________________________________________________________________________________
# multimap
A multimap is an associative container in C++ that allows you to store multiple values for a single key.

### Syntax
```cpp
std::multimap<int, std::string> mm;
```
### insertion Key-Value Pairs
```cpp
mm.insert({1, "apple"});
mm.insert({2, "banana"});
mm.insert({1, "avocado"});
mm.insert({3, "cherry"});
mm.insert({2, "blueberry"});
```
### Accessing Values for a Specific Key
```cpp
int key = 1;
auto range = mm.equal_range(key);
std::cout << "\nValues for key " << key << ":\n";
```
### example
```cpp
#include <iostream>
#include <map>

int main() {
    // Creating a multimap
    std::multimap<int, std::string> mm;

    // Inserting key-value pairs
    mm.insert({1, "apple"});
    mm.insert({2, "banana"});
    mm.insert({1, "avocado"});
    mm.insert({3, "cherry"});
    mm.insert({2, "blueberry"});

    // Displaying elements
    std::cout << "Multimap elements:\n";
    for (const auto& pair : mm) {
        std::cout << pair.first << " => " << pair.second << "\n";
    }

    // Accessing values for a specific key
    int key = 1;
    auto range = mm.equal_range(key);
    std::cout << "\nValues for key " << key << ":\n";
    for (auto it = range.first; it != range.second; ++it) {
        std::cout << it->second << "\n";
    }

    return 0;
}
```
### Note
std::multimap is designed to handle scenarios where a single key may correspond to multiple values. 
This flexibility allows you to store duplicate keys, making it particularly useful for representing one-to-many relationships. 
For instance, if you wanted to manage multiple email addresses for a single contact or keep a log of events that occur at the same time, a multimap would be the better choice.

________________________________________________________________________________________________________________________________________________________________________
# set
A set is part of the Standard Template Library (STL) and represents a collection of unique elements that are sorted automatically. 
It allows for efficient insertion, deletion, and search operations.

## syntax
```cpp
std::set<int> mySet;               // declare a  set of integers
std::set<std::string> myStringSet; // declare a set of strings

std::set<int> mySet = {1, 2, 3, 4, 5};  //initialize a set

mySet.insert(6); // Adds 6 to the set
mySet.insert(3); // This will not add 3, since it already exists

mySet.erase(2); // Removes the element 2 from the set
```
checking for existence
```cpp
if (mySet.find(3) != mySet.end()) {
    std::cout << "3 is in the set." << std::endl;
} else {
    std::cout << "3 is not in the set." << std::endl;
}
```
### Example
```cpp
#include <iostream>
#include <set>

int main() {
    std::set<int> mySet;

    // Adding elements
    mySet.insert(3);
    mySet.insert(1);
    mySet.insert(4);
    mySet.insert(1); // Duplicate, will not be added

    // Iterating over the set
    std::cout << "Elements in the set: ";
    for (const auto& element : mySet) {
        std::cout << element << " ";
    }
    std::cout << std::endl;

    // Removing an element
    mySet.erase(1);
    std::cout << "After removing 1: ";
    for (const auto& element : mySet) {
        std::cout << element << " ";
    }
    std::cout << std::endl;

    // Checking for existence
    if (mySet.find(3) != mySet.end()) {
        std::cout << "3 is in the set." << std::endl;
    } else {
        std::cout << "3 is not in the set." << std::endl;
    }

    return 0;
}
```
### Note
Sets are useful when you need to maintain a collection of unique elements and want to perform efficient searches, insertions, and deletions. They automatically sort their elements, and their operations generally have logarithmic time complexity due to their underlying balanced tree structure.

________________________________________________________________________________________________________________________________________________
# map
A map is part of the Standard Template Library (STL) and provides a sorted associative container that stores elements in key-value pairs. 
Each key must be unique, and the map automatically sorts the keys.

### syntax
```cpp

std::map<int, std::string> myMap; // declaring a map with integer keys and string values
std::map<std::string, int> ageMap; // declaring a map with string keys and integer values

std::map<std::string, int> ageMap = {   //Initializing a Map
    {"Alice", 30},
    {"Bob", 25},
    {"Charlie", 35}
};

myMap[1] = "One";          // assing an element using []
myMap.insert({2, "Two"});  // Using insert()

myMap.erase(1); // Removes the element with key 1
```

### Example
```cpp

#include <iostream>
#include <map>

int main() {
    std::map<std::string, int> ageMap;

    // Adding elements
    ageMap["Alice"] = 30;
    ageMap["Bob"] = 25;
    ageMap["Charlie"] = 35;

    // Accessing elements
    std::cout << "Alice's age: " << ageMap["Alice"] << std::endl;

    // Iterating over the map
    std::cout << "All ages:\n";
    for (const auto& pair : ageMap) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }

    // Removing an element
    ageMap.erase("Bob");

    std::cout << "After removing Bob:\n";
    for (const auto& pair : ageMap) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }

    return 0;
}
````

_________________________________________________________________________________________________________________________________________________________________________________________________________
# list
 list is part of the Standard Template Library (STL) and represents a doubly linked list. 
 It allows for efficient insertion and removal of elements from any position, but accessing elements by index is less 
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
# vector
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

