#include <iostream>
#include <vector>
#include <algorithm> // For reverse
#include <cstdlib>   // For abs

using namespace std;
//link: https://leetcode.com/problems/left-and-right-sum-differences/
class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size();
        vector<int> pref(n, 0), suf(n + 1, 0);

        // Calculating prefix sums
        for (int i = 1; i < n; i++) {
            pref[i] = pref[i - 1] + nums[i - 1];
        }
        
        // Calculating suffix sums
        reverse(nums.begin(), nums.end());
        for (int i = 1; i <= n; i++) {
            suf[i] = suf[i - 1] + nums[i - 1];
        }
        reverse(suf.begin(), suf.end());
        suf.erase(suf.begin());

        // Calculating absolute differences
        for (int i = 0; i < n; i++) {
            int res = abs(pref[i] - suf[i]);
            ans.push_back(res);
        }
        return ans;
    }
};

int main() {
    Solution sol;

    // Test case 1
    vector<int> nums1 = {1, 2, 3, 4, 5};
    vector<int> result1 = sol.leftRightDifference(nums1);

    cout << "Left-right difference for test case 1: ";
    for (int value : result1) {
        cout << value << " ";
    }
    cout << endl;

    // Test case 2
    vector<int> nums2 = {10, 20, 30, 40, 50};
    vector<int> result2 = sol.leftRightDifference(nums2);

    cout << "Left-right difference for test case 2: ";
    for (int value : result2) {
        cout << value << " ";
    }
    cout << endl;

    return 0;
}
