#include <iostream>

int main() 
{
    int arr[] = {1, 2, 3, 4, 6, 7, 8};
    int originalSize = sizeof(arr) / sizeof(arr[0]);
    int newSize = originalSize + 1;
    int newArr[newSize];

    int valueToInsert = 5;
    int insertIndex = 3;

    for (int i = 0; i < insertIndex; ++i) 
	{
        newArr[i] = arr[i];
    }

    newArr[insertIndex] = valueToInsert;

    for (int i = insertIndex; i < originalSize; ++i) 
	{
        newArr[i + 1] = arr[i];
    }

    std::cout << "Modified array: ";
    for (int i = 0; i < newSize; ++i) 
	{
        std::cout << newArr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
