#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//Link: https://leetcode.com/problems/arithmetic-subarrays/
class Solution {
public:
    // Function to check if the subarray from index i to j is an arithmetic subarray
    bool solve(int i, int j, vector<int>& nums) {
        if (j - i + 1 < 2) {
            return true;
        }
        sort(nums.begin() + i, nums.begin() + j + 1);
        int diff = nums[i + 1] - nums[i];
        for (int k = i + 1; k < j; k++) {
            if (nums[k + 1] - nums[k] != diff) {
                return false;
            }
        }
        return true;
    }

    // Function to check if each subarray defined by l and r is an arithmetic subarray
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        int m = l.size();
        vector<bool> ans;
        for (int i = 0; i < m; i++) {
            ans.push_back(solve(l[i], r[i], nums));
        }
        return ans;
    }
};

int main() {
    Solution sol;

    // Example input
    vector<int> nums = {4, 6, 5, 9, 3, 7};
    vector<int> l = {0, 1, 2};
    vector<int> r = {2, 3, 5};

    // Call the checkArithmeticSubarrays method
    vector<bool> result = sol.checkArithmeticSubarrays(nums, l, r);

    // Output the results
    for (bool res : result) {
        cout << (res ? "true" : "false") << endl;
    }

    return 0;
}
