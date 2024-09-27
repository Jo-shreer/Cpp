#include <iostream>
#include <vector>

using namespace std;

int findMissingNumber(const vector<int> &nums) 
{
    int n = nums.size();
   
    int expectedSum = (n + 1) * (n + 2) / 2;
    
    int actualSum = 0;
    for (int num : nums) {
        actualSum += num;
    }
    
    return expectedSum - actualSum;
}

int main() 
{
    vector<int> nums = {1, 2, 4, 5, 6};
    int missingNumber = findMissingNumber(nums);
    cout << "The missing number is: " << missingNumber << endl;
    return 0;
}


// output
// The missing number is: 3
