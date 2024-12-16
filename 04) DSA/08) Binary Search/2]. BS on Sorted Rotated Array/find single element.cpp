#include <iostream>
#include <vector>
using namespace std;
//Link: https://leetcode.com/problems/single-element-in-a-sorted-array/
class Solution {
public:
    // Function to find the single element that appears only once in a sorted array
    int singleNonDuplicate(vector<int>& nums) {
        int s = 0, e = nums.size() - 1;
        while (s < e) {
            int mid = (s + e) / 2;
            // Ensure mid is always even
            if (mid % 2 == 1) {
                mid--;
            }
            // Check if the single element is on the left side or right side
            if (nums[mid] != nums[mid + 1]) {
                e = mid;
            } else {
                s = mid + 2;
            }
        }
        return nums[s];
    }
};

int main() {
    Solution sol;

    // Example test cases
    vector<vector<int>> testCases = {
        {1, 1, 2, 3, 3, 4, 4, 8, 8},   // 2 appears only once
        {3, 3, 7, 7, 10, 11, 11},       // 10 appears only once
        {0, 1, 1, 2, 2, 3, 3, 4, 4, 5, 5}, // 0 appears only once
        {1, 1, 2, 3, 3, 4, 4, 5, 5, 6, 6}  // 2 appears only once
    };

    // Testing singleNonDuplicate function
    for (const auto& nums : testCases) {
        int singleElement = sol.singleNonDuplicate(const_cast<vector<int>&>(nums));
        cout << "The single non-duplicate element in the array is " << singleElement << "." << endl;
    }

    return 0;
}
