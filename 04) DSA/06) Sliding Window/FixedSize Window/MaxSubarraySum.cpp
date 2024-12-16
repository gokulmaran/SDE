#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;
//link: https://leetcode.com/problems/maximum-sum-of-distinct-subarrays-with-length-k/description/
class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        long long sum = 0, maxi = 0;
        
        // Initialize the first window
        for (int i = 0; i < k; i++) {
            m[nums[i]]++;
            sum += nums[i];
        }
        
        if (m.size() == k) maxi = sum;
        
        // Slide the window over the array
        for (int i = k; i < nums.size(); i++) {
            sum += nums[i];
            sum -= nums[i - k];
            m[nums[i]]++;
            m[nums[i - k]]--;
            
            if (m[nums[i - k]] == 0) m.erase(nums[i - k]);
            
            if (m.size() == k) {
                maxi = max(maxi, sum);
            }
        }
        
        return maxi;
    }
};

int main() {
    Solution solution;

    // Test case 1
    vector<int> nums1 = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int k1 = 3;
    long long result1 = solution.maximumSubarraySum(nums1, k1);
    cout << "Maximum sum of a subarray with " << k1 << " distinct elements in [1, 2, 3, 4, 5, 6, 7, 8, 9]: " << result1 << endl;

    // Test case 2
    vector<int> nums2 = {4, 4, 4, 4, 4, 4, 4};
    int k2 = 2;
    long long result2 = solution.maximumSubarraySum(nums2, k2);
    cout << "Maximum sum of a subarray with " << k2 << " distinct elements in [4, 4, 4, 4, 4, 4, 4]: " << result2 << endl;

    // Test case 3
    vector<int> nums3 = {1, 2, 3, 4, 5, 1, 2, 3, 4};
    int k3 = 4;
    long long result3 = solution.maximumSubarraySum(nums3, k3);
    cout << "Maximum sum of a subarray with " << k3 << " distinct elements in [1, 2, 3, 4, 5, 1, 2, 3, 4]: " << result3 << endl;

    return 0;
}
