#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int arr[4] = {1,2,3,4};
    vector<int> v = {5,6,7,8};  
    
    for(auto num: v)
        cout <<"num:" << num << endl;
}

// C++ extends the support of initializer list
// vector<int> v = {1,2,3,4}; 
