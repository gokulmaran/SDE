#include <iostream>
#include <vector>

using namespace std;
//link: https://leetcode.com/problems/sort-array-by-parity-ii/description/
class Solution {
public:
    // Function to sort the array such that even-indexed positions contain even numbers
    // and odd-indexed positions contain odd numbers
    vector<int> sortArrayByParityII(vector<int>& nums) {
        int n = nums.size();
        int i = 0, j = 1;
        while (i < n && j < n) {
            // If current position i has an even number, move to the next even index
            if (nums[i] % 2 == 0) {
                i += 2;
            }
            // If current position j has an odd number, move to the next odd index
            else if (nums[j] % 2 == 1) {
                j += 2;
            }
            // If an even number is in an odd position and vice versa, swap them
            else {
                swap(nums[i], nums[j]);
                i += 2;
                j += 2;
            }
        }
        return nums;
    }
};

int main() {
    Solution sol;

    // Test case 1
    vector<int> nums1 = {4, 2, 5, 7};

    // Test case 2
    vector<int> nums2 = {1, 2, 3, 4, 5, 6};

    // Sort the arrays by parity
    vector<int> result1 = sol.sortArrayByParityII(nums1);
    vector<int> result2 = sol.sortArrayByParityII(nums2);

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
