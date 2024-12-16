#include <iostream>
#include <vector>

using namespace std;
//link: https://leetcode.com/problems/running-sum-of-1d-array/description/
class Solution {
public:
    // Function to compute the running sum of an array
    vector<int> runningSum(vector<int>& nums) {
        // Calculate running sum in-place
        for (int i = 1; i < nums.size(); i++) {
            nums[i] += nums[i - 1];
        }
        return nums; // Return the modified array with running sum
    }
};

int main() {
    Solution sol;

    // Test case 1
    vector<int> nums1 = {1, 2, 3, 4};
    // Expected output: {1, 3, 6, 10}

    // Test case 2
    vector<int> nums2 = {1, 1, 1, 1};
    // Expected output: {1, 2, 3, 4}

    // Calculate the running sum for each test case
    vector<int> result1 = sol.runningSum(nums1);
    vector<int> result2 = sol.runningSum(nums2);

    // Output the results
    cout << "Test case 1: Running sum is ";
    for (int num : result1) {
        cout << num << " ";
    }
    cout << endl;

    cout << "Test case 2: Running sum is ";
    for (int num : result2) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
