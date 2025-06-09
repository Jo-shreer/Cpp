/*
vector 
1. stores elements contiguously in memory.
2. Think of it like a dynamic array that can resize automatically when more space is needed.
3. Provides fast random access to elements using indices (operator[]).
4. Supports efficient insertion and removal at the end (push_back and pop_back).
5. Ideal when you need fast access and dynamic resizing.

std::vector<int> v = {1, 2, 3, 4};
// Size and capacity
v.size();
v.empty();
v.capacity();
v.resize(10);

// Modifying
v.push_back(5);
v.pop_back();
v.insert(v.begin(), 10);
v.erase(v.begin());
v.clear();
v.assign(5, 100);

// Access
v.front();
v.back();
v[2];

*/

#include <iostream>
#include <vector>
int main() 
{
    std::vector<int> numbers;
    numbers.push_back(10);
    numbers.push_back(20);
    numbers.push_back(30);
   
    for (const int& num : numbers) 
    {
        std::cout << num << " ";
    }
   
    numbers[1] = 25;
    std::cout << "After modification: ";
    for (const int& num : numbers) 
    {
        std::cout << num << " "; 
    }
    
    std::cout << std::endl;
    numbers.pop_back();
    std::cout << "After pop: ";
    for (const int& num : numbers) 
    {
        std::cout << num << " "; 
    }
    
    std::cout << std::endl;
    return 0;
}
