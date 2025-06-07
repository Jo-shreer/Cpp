/*
unordered_set
1. Elements are not ordered — no guaranteed order when you iterate.
2. Stores unique elements — no duplicates allowed.
3. Implemented using a hash table.
4. Average time complexity for lookup, insertion, and deletion is O(1).
5. Useful when you want to quickly check if an element exists.
*/

#include <iostream>
#include <unordered_set>
using namespace std;

int main() 
{
    unordered_set<int> mySet;
    mySet.insert(10);
    mySet.insert(20);
    mySet.insert(30);

    // Attempt to insert duplicate
    auto result = mySet.insert(20);  // result.second == false

    if (!result.second) 
    {
        cout << "20 already exists in the set\n";
    }
  // Iterate and print elements (order not guaranteed)
    for (int x : mySet) 
    {
        cout << x << " ";
    }
    cout << "\n";
    return 0;
}

o/p
20 already exists in the set
30 20 10 


