#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> v ={1,2,3,4,5};
    int size = v.size();
    int temp = v[0];
    
    for(int value: v)
    {
        cout << value << " ";
    }
    cout << endl;
    for(int i = 1; i < size; i++)
    {
       v[i-1] = v[i];
    }
   
    v[size - 1] = temp;
    
    for(int value: v)
    {
        cout << value << " ";
    }
    return 0;
}
