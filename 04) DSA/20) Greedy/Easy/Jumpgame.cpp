#include <iostream>
#include <vector>

using namespace std;
//Link: https://leetcode.com/problems/jump-game/
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int i = 0, n = nums.size();
        for (int reach = 0; i < n && i <= reach; ++i) {
            reach = max(i + nums[i], reach);
        }
        return i == n;
    }
};

int main() {
    Solution solution;

    // Example 1
    vector<int> nums1 = {2, 3, 1, 1, 4};
    bool result1 = solution.canJump(nums1);
    cout << "Can jump to the end of nums1? " << (result1 ? "Yes" : "No") << endl;

    // Example 2
    vector<int> nums2 = {3, 2, 1, 0, 4};
    bool result2 = solution.canJump(nums2);
    cout << "Can jump to the end of nums2? " << (result2 ? "Yes" : "No") << endl;

    // Example 3
    vector<int> nums3 = {2, 0, 0, 0, 2};
    bool result3 = solution.canJump(nums3);
    cout << "Can jump to the end of nums3? " << (result3 ? "Yes" : "No") << endl;

    // Example 4
    vector<int> nums4 = {0};
    bool result4 = solution.canJump(nums4);
    cout << "Can jump to the end of nums4? " << (result4 ? "Yes" : "No") << endl;

    return 0;
}
