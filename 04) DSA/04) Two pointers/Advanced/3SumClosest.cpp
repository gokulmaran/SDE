#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;
//link: https://leetcode.com/problems/3sum-closest/description/
class Solution {
public:
    // Function to find the sum of three integers in the array closest to the target
    int threeSumClosest(vector<int>& nums, int target) {
        int res = 0;
        int minDiff = INT_MAX;
        sort(nums.begin(), nums.end()); // Sort the array
        for (int i = 0; i < nums.size(); i++) {
            int j = i + 1;
            int k = nums.size() - 1;
            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if (abs(sum - target) < minDiff) {
                    minDiff = abs(sum - target);
                    res = sum; // Update the result to the closest sum
                }
                if (sum < target) {
                    j++; // Move the left pointer to the right
                } else {
                    k--; // Move the right pointer to the left
                }
            }
        }
        return res; // Return the closest sum
    }
};

int main() {
    Solution sol;

    // Test case 1
    vector<int> nums1 = {-1, 2, 1, -4};
    int target1 = 1;

    // Test case 2
    vector<int> nums2 = {0, 0, 0};
    int target2 = 1;

    // Find the sum of three integers closest to the target for each test case
    int result1 = sol.threeSumClosest(nums1, target1);
    int result2 = sol.threeSumClosest(nums2, target2);

    // Output the results
    cout << "Test case 1: " << result1 << endl;
    cout << "Test case 2: " << result2 << endl;

    return 0;
}
