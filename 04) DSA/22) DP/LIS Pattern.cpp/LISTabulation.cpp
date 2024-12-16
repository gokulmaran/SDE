#include <iostream>
#include <vector>

using namespace std;
//Link: https://leetcode.com/problems/longest-increasing-subsequence/description/
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 0);
        dp[0] = 1;
        int ans = 1;
        for (int i = 1; i < n; i++) {
            for (int j = i - 1; j >= 0; j--) {
                if (nums[j] < nums[i] && dp[i] < dp[j]) {
                    dp[i] = dp[j];
                }
            }
            dp[i]++;
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};

int main() {
    Solution solution;

    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};

    int result = solution.lengthOfLIS(nums);
    cout << "Length of Longest Increasing Subsequence is: " << result << endl;

    return 0;
}
