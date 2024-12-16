#include <iostream>
#include <vector>

using namespace std;
//Link: https://leetcode.com/problems/sort-array-by-parity/description/
class Solution {
public:
    // Function to sort the array such that all even numbers appear before odd numbers
    vector<int> sortArrayByParity(vector<int>& nums) {
        int i = 0; // Pointer to the position for the next even number
        for (int j = 0; j < nums.size(); j++) {
            if (nums[j] % 2 == 0) {
                // Swap even number to the front
                swap(nums[i], nums[j]);
                i++;
            }
        }
        return nums;
    }
};

int main() {
    Solution sol;

    // Test case 1
    vector<int> nums1 = {3, 1, 2, 4};

    // Test case 2
    vector<int> nums2 = {0, 5, 2, 6, 1, 7};

    // Sort arrays by parity
    vector<int> result1 = sol.sortArrayByParity(nums1);
    vector<int> result2 = sol.sortArrayByParity(nums2);

    // Output the results
    cout << "Array after sorting by parity (test case 1): ";
    for (int num : result1) {
        cout << num << " ";
    }
    cout << endl;

    cout << "Array after sorting by parity (test case 2): ";
    for (int num : result2) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
