#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

//Link:https://leetcode.com/problems/target-sum/description/
// Solution class with the method to find target sum ways
class Solution {
public:
    int solve(vector<int>& nums, int target, int idx, unordered_map<string, int>& dp) {
        if (idx == nums.size()) {
            if (target == 0) {
                return 1;
            }
            return 0;
        }

        string key = to_string(idx) + " " + to_string(target);
        if (dp.find(key) != dp.end()) {
            return dp[key];
        }

        int x = solve(nums, target - nums[idx], idx + 1, dp);
        int y = solve(nums, target + nums[idx], idx + 1, dp);
        return dp[key] = x + y;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        unordered_map<string, int> dp;
        return solve(nums, target, 0, dp);
    }
};

// Main function to test the Solution
int main() {
    Solution sol;

    // Test case 1
    vector<int> nums1 = {1, 1, 1, 1, 1};
    int target1 = 3;
    cout << "Number of ways to achieve target " << target1 << ": " 
         << sol.findTargetSumWays(nums1, target1) << endl;

    // Test case 2
    vector<int> nums2 = {1, 2, 3};
    int target2 = 4;
    cout << "Number of ways to achieve target " << target2 << ": " 
         << sol.findTargetSumWays(nums2, target2) << endl;

    // Test case 3
    vector<int> nums3 = {1, 2, 1};
    int target3 = 2;
    cout << "Number of ways to achieve target " << target3 << ": " 
         << sol.findTargetSumWays(nums3, target3) << endl;

    return 0;
}
