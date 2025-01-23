#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> findDuplicates(const vector<int>& arr) 
{
    unordered_map<int, int> frequencyMap;
    vector<int> duplicates;

    for (int num : arr)         // Count frequency of each element
    {
        frequencyMap[num]++;
    }

    for (auto pair : frequencyMap)   // Check for elements with frequency > 1
    {
        if (pair.second > 1) {
            duplicates.push_back(pair.first);
        }
    }

    return duplicates;
}

int main() {
    vector<int> array = {1, 2, 3, 4, 5, 2, 7, 8, 7, 9};
    vector<int> duplicates = findDuplicates(array);

    cout << "Duplicates in the array: ";
    for (int num : duplicates) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
