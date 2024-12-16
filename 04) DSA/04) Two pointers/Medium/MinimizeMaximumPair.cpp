#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
//Link: https://leetcode.com/problems/minimize-maximum-pair-sum-in-array/description/
class Solution {
public:
    // Function to find the minimum possible maximum pair sum
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end()); // Sort the array
        int i = 0, j = nums.size() - 1;
        int ans = 0;
        while (i <= j) {
            int sum = nums[i] + nums[j];
            ans = max(ans, sum); // Update the maximum pair sum
            i++;
            j--;
        }
        return ans;
    }
};

int main() {
    Solution sol;

    // Test case 1
    vector<int> nums1 = {3, 5, 2, 3};

    // Test case 2
    vector<int> nums2 = {1, 2, 3, 4, 5, 6};

    // Find the minimum possible maximum pair sum for each test case
    int result1 = sol.minPairSum(nums1);
    int result2 = sol.minPairSum(nums2);

    // Output the results
    cout << "Minimum possible maximum pair sum (test case 1): " << result1 << endl;
    cout << "Minimum possible maximum pair sum (test case 2): " << result2 << endl;

    return 0;
}
