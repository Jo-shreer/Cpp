#include <stdio.h>

int findSecondLargest(int arr[], int n) 
{
    if (n < 2) 
    {
        return -1; // Not enough elements
    }
    
    int largest = arr[0];
    int secondLargest = -1;
    
    for (int i = 1; i < n; i++) 
    {
        if (arr[i] > largest) 
        {
            secondLargest = largest;
            largest = arr[i];
        } 
        else if (arr[i] > secondLargest && arr[i] != largest) 
        {
            secondLargest = arr[i];
        }
    }
    
    return secondLargest;
}

int main() 
{
    int arr[] = {1, 5, 3, 9, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Second Largest Element: %d\n", findSecondLargest(arr, n));
    return 0;
}
