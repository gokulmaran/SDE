#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
//Link:https://leetcode.com/problems/largest-divisible-subset/description/
vector<int> largestDivisibleSubset(vector<int>& nums) {
    int n = nums.size();
    if (n == 0) return {};
    sort(nums.begin(), nums.end());

    vector<int> dp(n, 1);
    vector<int> prev_ind(n, -1);
    int max_ind = 0;

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (nums[i] % nums[j] == 0 && dp[i] < dp[j] + 1) {
                dp[i] = dp[j] + 1;
                prev_ind[i] = j;
            }
        }
        if (dp[i] > dp[max_ind]) {
            max_ind = i;
        }
    }

    vector<int> ans;
    int t = max_ind;
    while (t >= 0) {
        ans.push_back(nums[t]);
        t = prev_ind[t];
    }
    reverse(ans.begin(), ans.end());  // The subset needs to be reversed to get the correct order.
    return ans;
}

int main() {
    vector<int> nums = {1, 2, 3, 4, 6, 12};

    vector<int> result = largestDivisibleSubset(nums);
    
    cout << "Largest Divisible Subset: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
