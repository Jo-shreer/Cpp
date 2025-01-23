#include <iostream>
#include <climits>  // For INT_MIN
using namespace std;

int findSecondLargest(int arr[], int size) 
{
    int largest = INT_MIN;
    int secondLargest = INT_MIN;

    for (int i = 0; i < size; i++) 
    {
        if (arr[i] > largest) 
        {
            secondLargest = largest;  // Update second largest
            largest = arr[i];         // Update largest
        }
        else if (arr[i] > secondLargest && arr[i] != largest) 
        {
            secondLargest = arr[i];  // Update second largest
        }
    }
    return secondLargest;
}

int main() {
    int arr[] = {12, 3, 5, 7, 19, 19};  // Example array
    int size = sizeof(arr) / sizeof(arr[0]);  // Calculate size of the array

    int secondLargestElement = findSecondLargest(arr, size);
    
    if (secondLargestElement != INT_MIN) 
    {
        cout << "The second largest element in the array is: " << secondLargestElement << endl;
    } else 
    {
        cout << "There is no second largest element." << endl;
    }

    return 0;
}

/*output*/
The second largest element in the array is: 12
