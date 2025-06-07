/*
vector 
It is a sequence container in C++ STL that stores elements contiguously in memory.
Think of it like a dynamic array that can resize automatically when more space is needed.
Provides fast random access to elements using indices (operator[]).
Supports efficient insertion and removal at the end (push_back and pop_back).
Ideal when you need fast access and dynamic resizing.
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
