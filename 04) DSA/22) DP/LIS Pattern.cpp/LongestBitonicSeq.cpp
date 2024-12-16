#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
//Link:https://www.geeksforgeeks.org/problems/longest-bitonic-subsequence0824/1
vector<int> LIS(vector<int>& arr, int n) {
    vector<int> dp(n, 1);
    int maxi = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[j] < arr[i] && 1 + dp[j] > dp[i]) {
                dp[i] = max(1 + dp[j], dp[i]);
            }
        }
        maxi = max(maxi, dp[i]);
    }
    return dp;
}

int LongestBitonicSequence(int n, vector<int>& nums) {
    vector<int> forward = LIS(nums, n);
    reverse(nums.begin(), nums.end());
    vector<int> reverse = LIS(nums, n);
    int maxi = 0;
    for (int i = 0; i < n; i++) {
        int term = 0;
        if (forward[i] > 1 && reverse[n - i - 1] > 1) {
            term = forward[i] + reverse[n - i - 1];
        }
        maxi = max(maxi, term);
    }
    if (maxi == 0) return 0;
    return maxi - 1;
}

int main() {
    vector<int> nums = {1, 2, 1, 3, 2, 1};

    int n = nums.size();
    int result = LongestBitonicSequence(n, nums);

    cout << "Length of the longest bitonic subsequence is: " << result << endl;

    return 0;
}
