#include <iostream>
using namespace std;

int findMax(int arr[], int size) 
{
    int max = arr[0];               // Assume the first element is the largest
    for (int i = 1; i < size; i++) 
    {
        if (arr[i] > max) 
        {
            max = arr[i]; // Update the max if a larger element is found
        }
    }
    return max;
}

int main() {
    int arr[] = {12, 3, 5, 7, 19, 0};  // Example array
    int size = sizeof(arr) / sizeof(arr[0]);  // Calculate the size of the array

    int maxElement = findMax(arr, size);
    cout << "The maximum element in the array is: " << maxElement << endl;

    return 0;
}

/*output*/

The maximum element in the array is: 19
