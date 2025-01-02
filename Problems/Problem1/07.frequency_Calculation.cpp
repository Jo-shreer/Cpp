#include<iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int arr[6] = {1,2,3,1,2,3};
    int size = sizeof(arr)/sizeof(arr[0]);
    int new_arr[size+1] = {0};
    
    for(int i = 0; i < size ; i++)
    {
       new_arr[arr[i]]++;
       cout << "arr:" << arr[i] << " "; 
    }
    
    cout << endl;
    
    for(int i = 0; i < size ; i++)
    {
       cout << i << ":" << new_arr[i] << " "; 
    }
    
    return 0;
}
