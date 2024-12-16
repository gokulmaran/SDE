#include <iostream>
#include <vector>

using namespace std;
//Link: https://leetcode.com/problems/partition-equal-subset-sum/description/
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        int n = nums.size();
        
        for (int i = 0; i < n; i++) {
            sum += nums[i];
        }
        
        // If sum is odd, it cannot be partitioned into two equal subsets
        if (sum % 2 != 0) return false;
        
        int target = sum / 2;
        vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));
        
        // Base case: a sum of 0 can always be achieved with any subset
        for (int i = 0; i <= n; i++) {
            dp[i][0] = 1;
        }
        
        // Fill the dp table
        for (int ind = 1; ind <= n; ind++) {
            for (int t = 1; t <= target; t++) {
                bool notTake = dp[ind - 1][t];
                bool take = false;
                if (nums[ind - 1] <= t) take = dp[ind - 1][t - nums[ind - 1]];

                dp[ind][t] = take || notTake;
            }
        }
        
        return dp[n][target];
    }
};

int main() {
    // Example usage:
    Solution solution;

    // Test case 1
    vector<int> nums1 = {1, 5, 11, 5};
    bool result1 = solution.canPartition(nums1);
    cout << "Can partition [1, 5, 11, 5]? " << (result1 ? "Yes" : "No") << endl;

    // Test case 2
    vector<int> nums2 = {1, 2, 3, 5};
    bool result2 = solution.canPartition(nums2);
    cout << "Can partition [1, 2, 3, 5]? " << (result2 ? "Yes" : "No") << endl;

    return 0;
}
