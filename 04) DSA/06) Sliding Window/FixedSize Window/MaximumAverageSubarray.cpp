#include <iostream>
#include <vector>
#include <algorithm> // For max function

using namespace std;
//link: https://leetcode.com/problems/maximum-average-subarray-i/
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int maxSum = INT_MIN;
        int cursum = 0;
        
        // Compute the sum of the first window of size k
        for(int i = 0; i < k; i++) {
            cursum += nums[i];
        }
        maxSum = max(maxSum, cursum);
        
        // Slide the window across the array
        for(int i = k; i < nums.size(); i++) {
            cursum += nums[i];
            cursum -= nums[i - k];
            maxSum = max(maxSum, cursum);
        }
        
        // Calculate the maximum average
        double ans = (1.0) * maxSum / k;
        return ans;
    }
};

int main() {
    Solution solution;

    // Test case 1
    vector<int> nums1 = {1, 12, -5, -6, 50, 3};
    int k1 = 4;
    cout << "Maximum average of subarray of size " << k1 << " is: " 
         << solution.findMaxAverage(nums1, k1) << endl;

    // Test case 2
    vector<int> nums2 = {5, 5, 5, 5, 5};
    int k2 = 1;
    cout << "Maximum average of subarray of size " << k2 << " is: " 
         << solution.findMaxAverage(nums2, k2) << endl;

    // Test case 3
    vector<int> nums3 = {1, 2, 3, 4, 5, 6, 7};
    int k3 = 3;
    cout << "Maximum average of subarray of size " << k3 << " is: " 
         << solution.findMaxAverage(nums3, k3) << endl;

    return 0;
}
