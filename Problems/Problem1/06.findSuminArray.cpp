//Find the elements whose sum is 14

#include<iostream>
using namespace std;

int main()
{
    int arr[5] = {2,6,5,8,11};
    int add = 0;
    int sum = 14;
    
    for(int i = 0; i < 5; i++)
    {
        for(int j = i+1; j < 5; j++)
        {
            add = arr[i] + arr[j];
            if (add == sum)
                cout << "element:" << arr[i] << " and " << arr[j] << endl;
        }
    }
    
    return 0;
}

//output
//element: 6 and 8
