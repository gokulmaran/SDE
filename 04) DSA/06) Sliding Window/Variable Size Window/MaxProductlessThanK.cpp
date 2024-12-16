#include <iostream>
#include <vector>

using namespace std;
//link: https://leetcode.com/problems/subarray-product-less-than-k/description/
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int left = 0, right = 0, cnt = 0, product = 1;
        if (k <= 1) return 0;
        while (right < nums.size()) {
            product *= nums[right];
            while (product >= k) {
                product /= nums[left++];
            }
            cnt += (right - left + 1);
            right++;
        }
        return cnt;
    }
};

int main() {
    Solution solution;

    // Test case 1
    vector<int> nums1 = {10, 5, 2, 6};
    int k1 = 100;
    int result1 = solution.numSubarrayProductLessThanK(nums1, k1);
    cout << "Number of subarrays with product less than " << k1 << ": " << result1 << endl;

    // Test case 2
    vector<int> nums2 = {1, 2, 3, 4};
    int k2 = 10;
    int result2 = solution.numSubarrayProductLessThanK(nums2, k2);
    cout << "Number of subarrays with product less than " << k2 << ": " << result2 << endl;

    // Test case 3
    vector<int> nums3 = {1, 2, 3};
    int k3 = 5;
    int result3 = solution.numSubarrayProductLessThanK(nums3, k3);
    cout << "Number of subarrays with product less than " << k3 << ": " << result3 << endl;

    // Test case 4
    vector<int> nums4 = {1, 2, 3, 4, 5};
    int k4 = 15;
    int result4 = solution.numSubarrayProductLessThanK(nums4, k4);
    cout << "Number of subarrays with product less than " << k4 << ": " << result4 << endl;

    return 0;
}
