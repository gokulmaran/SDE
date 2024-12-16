#include <iostream>
#include <vector>

using namespace std;
//Link: https://www.geeksforgeeks.org/problems/partitions-with-given-difference/1
class Solution {
public:
    int mod = 1000000007;

    int countPartitions(int n, int d, vector<int>& arr) {
        int sum = 0;
        for (auto it : arr) sum += it;
        
        if (sum - d < 0 || (sum - d) % 2) return 0;
        
        int k = (sum - d) / 2;
        
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
        
        // Step1: Base case
        if (arr[0] == 0) dp[0][0] = 2;
        else dp[0][0] = 1;
        if (arr[0] != 0 && arr[0] <= k) dp[0][arr[0]] = 1;
        
        // Step2: Represent all states
        for (int ind = 1; ind < n; ind++) {
            for (int target = 0; target <= k; target++) {
                // Copy recursion
                int notTake = dp[ind - 1][target];
                
                int take = 0;
                if (arr[ind] <= target) take = dp[ind - 1][target - arr[ind]];
                
                dp[ind][target] = (take + notTake) % mod;
            }
        }
        return dp[n - 1][k];
    }
};

int main() {
    Solution solution;

    // Test case 1
    vector<int> arr1 = {1, 2, 3, 4, 5};
    int d1 = 3;
    int result1 = solution.countPartitions(arr1.size(), d1, arr1);
    cout << "Number of partitions for [1, 2, 3, 4, 5] with difference 3: " << result1 << endl;

    // Test case 2
    vector<int> arr2 = {1, 1, 1, 1, 1, 1};
    int d2 = 1;
    int result2 = solution.countPartitions(arr2.size(), d2, arr2);
    cout << "Number of partitions for [1, 1, 1, 1, 1, 1] with difference 1: " << result2 << endl;

    return 0;
}
