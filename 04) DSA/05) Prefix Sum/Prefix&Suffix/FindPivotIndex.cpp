#include <iostream>
#include <vector>

using namespace std;
//link: https://leetcode.com/problems/find-pivot-index/
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        vector<int> pre(n, 0), suf(n, 0);

        // Calculating prefix sums
        for (int i = 1; i < nums.size(); i++) {
            pre[0] = 0;
            pre[i] = pre[i - 1] + nums[i - 1];
        }

        // Calculating suffix sums
        suf[n - 1] = 0;
        for (int i = n - 2; i >= 0; i--) {
            suf[i] = suf[i + 1] + nums[i + 1];
        }

        // Finding the pivot index
        for (int i = 0; i < nums.size(); i++) {
            if (pre[i] == suf[i])
                return i;
        }
        return -1;
    }
};

int main() {
    Solution sol;

    // Test case 1
    vector<int> nums1 = {1, 7, 3, 6, 5, 6};
    int result1 = sol.pivotIndex(nums1);
    cout << "Pivot index for test case 1: " << result1 << endl;

    // Test case 2
    vector<int> nums2 = {1, 2, 3};
    int result2 = sol.pivotIndex(nums2);
    cout << "Pivot index for test case 2: " << result2 << endl;

    // Test case 3
    vector<int> nums3 = {2, 1, -1};
    int result3 = sol.pivotIndex(nums3);
    cout << "Pivot index for test case 3: " << result3 << endl;

    // Test case 4 (no pivot index)
    vector<int> nums4 = {1, 2, 3, 4, 5};
    int result4 = sol.pivotIndex(nums4);
    cout << "Pivot index for test case 4: " << result4 << endl;

    return 0;
}
