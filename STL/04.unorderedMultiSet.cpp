/*
An unordered_multiset 
1. It stores multiple elements with the same value (duplicates allowed).
2. Elements are not sorted, but organized in buckets using a hash function.
3. Provides fast average O(1) lookup, insertion, and deletion.
4. Implemented internally as a hash table.
5. unordered associative container
*/
#include <iostream>
#include <unordered_set>
using namespace std;

int main() 
{
    unordered_multiset<int> ums;
    ums.insert(10);
    ums.insert(20);
    ums.insert(10);
    ums.insert(30);
    ums.insert(20);

    // Iterate and print elements (order is unspecified)
    for (int x : ums) 
    {
        cout << x << " ";
    }
    // Count occurrences of 10
    cout << "Count of 10: " << ums.count(10) << "\n";
    return 0;
}
