#include <iostream>
#include <vector>

using namespace std;
//link: https://leetcode.com/problems/max-consecutive-ones-iii/
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int zero_count = 0;
        int l = 0, r = 0, ans = 0;
        for (r = 0; r < nums.size(); r++) {
            if (nums[r] == 0) {
                zero_count++;
            }
            while (zero_count > k) {
                if (nums[l] == 0) {
                    zero_count--;
                }
                l++;
            }
            ans = max(ans, r - l + 1);
        }
        return ans;
    }
};

int main() {
    Solution solution;

    // Test case 1
    vector<int> nums1 = {1, 1, 0, 0, 1, 1, 1, 0, 1, 1};
    int k1 = 2;
    int result1 = solution.longestOnes(nums1, k1);
    cout << "Longest sequence of ones with up to " << k1 << " zeroes: " << result1 << endl;

    // Test case 2
    vector<int> nums2 = {0, 0, 0, 0, 0};
    int k2 = 2;
    int result2 = solution.longestOnes(nums2, k2);
    cout << "Longest sequence of ones with up to " << k2 << " zeroes: " << result2 << endl;

    // Test case 3
    vector<int> nums3 = {1, 1, 1, 1, 1};
    int k3 = 1;
    int result3 = solution.longestOnes(nums3, k3);
    cout << "Longest sequence of ones with up to " << k3 << " zeroes: " << result3 << endl;

    // Test case 4
    vector<int> nums4 = {1, 0, 1, 0, 1, 0, 1, 0, 1};
    int k4 = 3;
    int result4 = solution.longestOnes(nums4, k4);
    cout << "Longest sequence of ones with up to " << k4 << " zeroes: " << result4 << endl;

    return 0;
}
