#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
//Link: https://leetcode.com/problems/number-of-longest-increasing-subsequence/description/
int findNumberOfLIS(vector<int>& nums) {
    int n = nums.size();
    vector<int> dp(n, 1);
    vector<int> cnt(n, 1);
    int maxLen = 1;

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (nums[i] > nums[j]) {
                if (dp[j] + 1 > dp[i]) {
                    dp[i] = dp[j] + 1;
                    cnt[i] = cnt[j];
                }
                else if (dp[j] + 1 == dp[i]) {
                    cnt[i] += cnt[j];
                }
            }
        }
        maxLen = max(maxLen, dp[i]);
    }

    int numOfLIS = 0;
    for (int i = 0; i < n; i++) {
        if (dp[i] == maxLen) {
            numOfLIS += cnt[i];
        }
    }
    return numOfLIS;
}

int main() {
    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};

    int result = findNumberOfLIS(nums);

    cout << "Number of longest increasing subsequences is: " << result << endl;

    return 0;
}
