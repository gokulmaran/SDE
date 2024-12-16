#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
//link: https://leetcode.com/problems/two-sum/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int i = 0, j = nums.size() - 1;
        vector<int> ans;
        
        // Sort the array to use two-pointer technique
        sort(nums.begin(), nums.end());

        while (i < j) {
            int sum = nums[i] + nums[j];
            if (sum == target) {
                ans.push_back(i);
                ans.push_back(j);
                break;
            } else if (sum < target) {
                i++;
            } else {
                j--;
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;

    // Test cases
    vector<int> nums1 = {2, 7, 11, 15};
    int target1 = 9;

    vector<int> nums2 = {1, 2, 3, 4, 5};
    int target2 = 9;

    // Find indices of the two numbers that add up to the target
    vector<int> result1 = sol.twoSum(nums1, target1);
    vector<int> result2 = sol.twoSum(nums2, target2);

    // Output the results
    cout << "Indices of numbers that add up to " << target1 << " are: ";
    if (!result1.empty()) {
        cout << result1[0] << " and " << result1[1] << endl;
    } else {
        cout << "No solution found." << endl;
    }

    cout << "Indices of numbers that add up to " << target2 << " are: ";
    if (!result2.empty()) {
        cout << result2[0] << " and " << result2[1] << endl;
    } else {
        cout << "No solution found." << endl;
    }

    return 0;
}
