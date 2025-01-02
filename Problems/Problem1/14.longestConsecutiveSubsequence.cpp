#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

int longestConsecutiveSubsequence(const vector<int>& nums) 
{
    unordered_set<int> numSet(nums.begin(), nums.end());
    int longestSequence = 0;

    for (int num : numSet) 
    {
        if (numSet.find(num - 1) == numSet.end()) // If the current number is the start of a sequence
        {
            int currentNum = num;
            int currentSequence = 1;

            while (numSet.find(currentNum + 1) != numSet.end())  // Count the consecutive numbers after the current number
            {
                currentNum++;
                currentSequence++;
            }

            longestSequence = max(longestSequence, currentSequence);
        }
    }

    return longestSequence;
}

int main() 
{
    vector<int> nums = {100, 4, 200, 1, 3, 2};
    int longestSeq = longestConsecutiveSubsequence(nums);
    cout << "Length of the longest consecutive subsequence: " << longestSeq << endl;

    return 0;
}
