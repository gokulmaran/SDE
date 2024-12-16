#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
//Link: https://leetcode.com/problems/partition-array-for-maximum-sum/
class Solution {
public:
    vector<int> dp;

    int solve(vector<int>& arr, int k, int ind) {
        int n = arr.size(), mx = 0, ans = 0;
        if (ind >= n) return 0;
        if (dp[ind] != -1) return dp[ind];

        for (int i = ind; i < min(ind + k, n); i++) {
            mx = max(mx, arr[i]);
            ans = max(ans, (i - ind + 1) * mx + solve(arr, k, i + 1));
        }
        dp[ind] = ans;
        return ans;
    }

    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        dp.resize(arr.size(), -1);
        return solve(arr, k, 0);
    }
};

int main() {
    Solution sol;

    // Example input
    vector<int> arr = {1, 15, 7, 9, 2, 5, 10};
    int k = 3;

    int result = sol.maxSumAfterPartitioning(arr, k);
    cout << "Maximum Sum After Partitioning: " << result << endl;

    return 0;
}
