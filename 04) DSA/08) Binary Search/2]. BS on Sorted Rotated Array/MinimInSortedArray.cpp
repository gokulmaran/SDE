#include <iostream>
#include <vector>
#include <climits>
using namespace std;
//Link: https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/
class Solution {
public:
    int findMin(vector<int>& nums) {
        int s = 0, e = nums.size() - 1;
        int ans = INT_MAX;
        while (s <= e) {
            int mid = (s + e) / 2;
            if (nums[s] <= nums[mid]) {
                ans = min(ans, nums[s]);
                s = mid + 1;
            } else {
                ans = min(ans, nums[mid]);
                e = mid - 1;
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;

    // Example rotated sorted arrays
    vector<vector<int>> testCases = {
        {3, 4, 5, 1, 2},
        {4, 5, 6, 7, 0, 1, 2},
        {11, 13, 15, 17},
        {2, 3, 4, 5, 1}
    };

    // Testing findMin function
    for (const auto& nums : testCases) {
        int minElement = sol.findMin(const_cast<vector<int>&>(nums));
        cout << "The minimum element in the array is " << minElement << "." << endl;
    }

    return 0;
}
