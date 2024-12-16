#include <iostream>
#include <vector>

using namespace std;
//Link: https://leetcode.com/problems/single-number/description/
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum ^= nums[i]; // XOR operation
        }
        return sum;
    }
};

int main() {
    Solution sol;

    // Test case 1
    vector<int> nums1 = {2, 2, 1};
    cout << "Single number in {2, 2, 1}: " << sol.singleNumber(nums1) << endl; // Expected output: 1

    // Test case 2
    vector<int> nums2 = {4, 1, 2, 1, 2};
    cout << "Single number in {4, 1, 2, 1, 2}: " << sol.singleNumber(nums2) << endl; // Expected output: 4

    // Test case 3
    vector<int> nums3 = {1, 0, 1};
    cout << "Single number in {1, 0, 1}: " << sol.singleNumber(nums3) << endl; // Expected output: 0

    // Test case 4
    vector<int> nums4 = {7, 8, 7, 9, 9};
    cout << "Single number in {7, 8, 7, 9, 9}: " << sol.singleNumber(nums4) << endl; // Expected output: 8

    return 0;
}
