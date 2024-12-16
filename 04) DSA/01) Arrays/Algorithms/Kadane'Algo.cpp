#include <iostream>
#include <vector>
#include <climits> // For INT_MIN

using namespace std;
//Link:https://leetcode.com/problems/maximum-subarray/description/
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int csum = 0;    // Current sum of the subarray
        int ans = INT_MIN; // Initialize the maximum sum to the smallest possible value

        // Traverse through the array
        for (int i = 0; i < nums.size(); i++) {
            csum += nums[i];          // Add the current element to the current sum
            ans = max(ans, csum);     // Update the maximum sum found so far
            if (csum < 0) {
                csum = 0;             // Reset the current sum if it becomes negative
            }
        }

        return ans; // Return the maximum sum of the contiguous subarray
    }
};

int main() {
    // Example vector with integers
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};

    // Create an instance of the Solution class
    Solution sol;

    // Calling the maxSubArray function to find the maximum sum of a contiguous subarray
    int result = sol.maxSubArray(nums);

    // Output the result
    cout << "The maximum sum of a contiguous subarray is: " << result << endl;

    return 0;
}
