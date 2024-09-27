#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int countPairsWithSum(const vector<int>& arr, int targetSum) 
{
    unordered_map<int, int> frequencyMap;
    int count = 0;

    for (int num : arr)     // Add elements to the frequency map
    {
        frequencyMap[num]++;
    }

    for (int num : arr)      // Check for pairs
    {
        int complement = targetSum - num;
        if (frequencyMap.find(complement) != frequencyMap.end()) 
        {
            count += frequencyMap[complement];
            if (complement == num)   // Avoid double counting the same pair
            {
                count--;
            }
        }
    }

    // Divide by 2 as each pair is counted twice
    return count / 2;
}

int main() 
{
    vector<int> array = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int targetSum = 10;
    int pairsCount = countPairsWithSum(array, targetSum);
    cout << "Number of pairs with sum " << targetSum << ": " << pairsCount << endl;

    return 0;
}
