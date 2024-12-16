#include <iostream>
#include <vector>

using namespace std;
//Link: https://leetcode.com/problems/remove-element/description/
class Solution {
public:
    // Function to remove all occurrences of 'val' from 'nums'
    int removeElement(vector<int>& nums, int val) {
        int k = 0; // Pointer to the position of the next element not equal to 'val'
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != val) {
                nums[k++] = nums[i]; // Move non-'val' elements to the front
            }
        }
        return k; // The new length of the array
    }
};

int main() {
    Solution sol;

    // Test case 1
    vector<int> nums1 = {3, 2, 2, 3};
    int val1 = 3;

    // Test case 2
    vector<int> nums2 = {0, 1, 2, 2, 3, 0, 4, 2};
    int val2 = 2;

    // Remove elements and get new length
    int newLength1 = sol.removeElement(nums1, val1);
    int newLength2 = sol.removeElement(nums2, val2);

    // Output the results
    cout << "Array after removing " << val1 << ": ";
    for (int i = 0; i < newLength1; i++) {
        cout << nums1[i] << " ";
    }
    cout << endl;

    cout << "Array after removing " << val2 << ": ";
    for (int i = 0; i < newLength2; i++) {
        cout << nums2[i] << " ";
    }
    cout << endl;

    return 0;
}
