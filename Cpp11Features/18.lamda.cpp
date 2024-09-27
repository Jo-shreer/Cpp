#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    vector<int> v = {1,2,3,4,21,2};
    for_each(v.begin(), v.end(), [](int &num){return num = num*2;});
    
    for(auto &value : v)
        cout << value << " ";    
    return 0;
}
