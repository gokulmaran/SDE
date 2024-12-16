#include <iostream>
#include <vector>
#include <climits> // For INT_MAX
#include <cmath>   // For abs

using namespace std;
//link: https://leetcode.com/problems/minimum-average-difference/
class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        int n = nums.size();
        long long rsum = 0, lsum = 0;
        
        // Calculate the total sum of the array
        for (auto i : nums) {
            rsum += i;
        }
        
        int mini = INT_MAX;
        int idx = 0;

        // Iterate through the array to find the minimum average difference
        for (int i = 0; i < n; i++) {
            lsum += nums[i];
            rsum -= nums[i];

            long long first = lsum / (i + 1);
            long long second = i < n - 1 ? rsum / (n - i - 1) : 0;
            int diff = abs(first - second);

            if (diff < mini) {
                mini = diff;
                idx = i;
            }
        }
        return idx;
    }
};

int main() {
    Solution sol;

    // Test case 1
    vector<int> nums1 = {2, 5, 3, 9, 5, 3};
    int result1 = sol.minimumAverageDifference(nums1);
    cout << "Index with minimum average difference for test case 1: " << result1 << endl;

    // Test case 2
    vector<int> nums2 = {0, 0, 0, 0, 0};
    int result2 = sol.minimumAverageDifference(nums2);
    cout << "Index with minimum average difference for test case 2: " << result2 << endl;

    // Test case 3
    vector<int> nums3 = {1, 2, 3, 4, 5, 6};
    int result3 = sol.minimumAverageDifference(nums3);
    cout << "Index with minimum average difference for test case 3: " << result3 << endl;

    // Test case 4
    vector<int> nums4 = {1, 3, 6, 7, 8, 9};
    int result4 = sol.minimumAverageDifference(nums4);
    cout << "Index with minimum average difference for test case 4: " << result4 << endl;

    return 0;
}
