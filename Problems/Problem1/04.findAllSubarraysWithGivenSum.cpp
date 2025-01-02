/*findAllSubarraysWithGivenSum*/

#include <bits/stdc++.h>
using namespace std;

int findAllSubarraysWithGivenSum(vector < int > & arr, int k) 
{
    int n = arr.size(); // size of the given array.{3, 1, 2, 4}, K = 6
    map<int, int> mpp;
    int preSum = 0;
    int cnt = 0;
    mpp[0] = 1; 
    
        for (int i = 0; i < n; i++) 
	{
        preSum += arr[i];
        cout <<"preSum:" << preSum << endl;

        int remove = preSum - k;			// Calculate x-k:
        cout << "remove:" << remove << endl;
		
        cnt += mpp[remove];					// Add the number of subarrays to be removed:
        cout <<"cnt:" << cnt << endl;
        mpp[preSum] += 1;
		
        for (auto value: mpp)
	{
            cout <<"value.first:" << value.first << endl;
            cout <<"value.second:" << value.second << endl;
        }
    }
    return cnt;
}
int main()
{
    vector<int> arr = {3, 1, 2, 4};
    int k = 6;
    int cnt = findAllSubarraysWithGivenSum(arr, k);
    cout << "The number of subarrays is: " << cnt << "\n";
    return 0;
}
