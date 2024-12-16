#include <iostream>
#include <vector>
#include <map>
using namespace std;
//link:https://leetcode.com/problems/subarrays-with-k-different-integers/description/
class Solution {
public:
    // Helper function to calculate number of subarrays with at most 'k' distinct integers
    int subarr(vector<int>& nums, int k) {
        int i = 0, j = 0, cnt = 0;
        map<int, int> m; // To store the frequency of elements in the current window
        
        while (j < nums.size()) {
            m[nums[j]]++; // Include the current element in the window
            // Shrink the window from the left if we have more than 'k' distinct integers
            while (m.size() > k) {
                m[nums[i]]--;
                if (m[nums[i]] == 0) {
                    m.erase(nums[i]); // Remove the element if its count is zero
                }
                i++; // Move the left boundary of the window
            }
            cnt += (j - i + 1); // Count the number of subarrays ending at 'j'
            j++; // Move the right boundary of the window
        }
        
        return cnt;
    }

    // Function to calculate number of subarrays with exactly 'k' distinct integers
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return subarr(nums, k) - subarr(nums, k - 1);
    }
};

int main() {
    Solution solution;

    // Test case 1: Typical case with a variety of numbers
    vector<int> nums1 = {1, 2, 1, 2, 3};
    int k1 = 2;
    cout << "Number of subarrays with exactly " << k1 << " distinct integers: "
         << solution.subarraysWithKDistinct(nums1, k1) << endl;

    // Test case 2: Case with a larger array and different k
    vector<int> nums2 = {1, 2, 1, 2, 3, 1, 2};
    int k2 = 3;
    cout << "Number of subarrays with exactly " << k2 << " distinct integers: "
         << solution.subarraysWithKDistinct(nums2, k2) << endl;

    // Test case 3: Case with k = 1
    vector<int> nums3 = {1, 1, 1, 1, 1};
    int k3 = 1;
    cout << "Number of subarrays with exactly " << k3 << " distinct integers: "
         << solution.subarraysWithKDistinct(nums3, k3) << endl;

    // Test case 4: Case with k larger than the number of distinct elements in the array
    vector<int> nums4 = {1, 2, 3};
    int k4 = 4;
    cout << "Number of subarrays with exactly " << k4 << " distinct integers: "
         << solution.subarraysWithKDistinct(nums4, k4) << endl;

    // Test case 5: Empty array
    vector<int> nums5 = {};
    int k5 = 2;
    cout << "Number of subarrays with exactly " << k5 << " distinct integers: "
         << solution.subarraysWithKDistinct(nums5, k5) << endl;

    return 0;
}
