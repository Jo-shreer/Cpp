/*
Majority of element is > N/2
Here N is 7
*/
#include<iostream>
using namespace std;

int main()
{
    int arr[7] = {2,2,3,3,1,2,2};
    int size = sizeof(arr)/sizeof(arr[0]);
    int maj = size/2;
    int hash[8] = {0};
    for(int i = 0; i < size; i++)
    {
        hash[arr[i]]++;
    }
    for(int i = 0; i < size; i++)
    {
        if(hash[i] > maj)
		{
           cout << endl;
           cout << "maj element is:" << i << endl;
        }
    }
    return 0;
}

//size:7
//maj element is:2
//output 
