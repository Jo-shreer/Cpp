#include <iostream>
#include <vector>
int main() 
{
    std::vector<int> numbers;
    numbers.push_back(10);
    numbers.push_back(20);
    numbers.push_back(30);
    std::cout << "Vector elements: ";
    for (const int& num : numbers) 
    {
        std::cout << num << " ";
    }
    std::cout << std::endl;
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
