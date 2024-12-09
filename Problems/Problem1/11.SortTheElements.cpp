#include <iostream>
using namespace std;

void sortArray(int arr[], int len)
{
    for(int i = 0; i < len; i++)
    {
        for(int j = 0; j < len -1; j++)
        {
            if(arr[j]> arr[j+1])
            {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

void printArray(int arr[], int len)
{
    for(int i = 0; i < len; i++)
    {
        cout << "array:" << arr[i] << " ";
    }
}

int main()
{
    int arr[6] = {1,2,3,4,58,9};
    int len = sizeof(arr)/sizeof(arr[0]);
    cout << "len:" << len << endl;
    sortArray(arr, len);
    printArray(arr,len);
    return 0;
}
