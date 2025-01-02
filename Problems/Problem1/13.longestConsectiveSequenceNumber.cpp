/*find the longestConsectiveSequenceNumber*/

#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> v = {100, 200, 1, 2, 3, 4};
    int size = v.size();
    int count = 0, maxlen = 0;
    int number = 0;
    int longest = 1;
    
    unordered_set<int> s;
	
    for(int i = 0; i < size; i++)
        s.insert(v[i]);
	
    for(int val: s)
        cout << val << " ";
	
    cout << endl; 
    for(auto element: s)
    {
        cout << "next element:" << element << endl;;
        if(s.find(element -1) == s.end())
        {
            count = 1;
            number = element;
            cout << "starting element1:" << number << endl;
            
            while(s.find(number + 1) != s.end())
            {
                cout << "number:" << number << endl;
                count = count+1;
                number = number +1;
                cout << "element2:" << number << endl;;
            }
            
            longest = max(longest, count);
        }
    }
    cout << endl;
    cout <<"longest:" << longest << endl;
        
        
    return 0;
}
