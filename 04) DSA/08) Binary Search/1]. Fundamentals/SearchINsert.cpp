#include <iostream>
#include <vector>
using namespace std;
//Link: https://leetcode.com/problems/search-insert-position/description/
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int s = 0, ans = nums.size(), e = nums.size() - 1;
        while (s <= e) {
            int mid = (s + e) / 2;
            if (nums[mid] >= target) {
                ans = mid;
                e = mid - 1;
            } else {
                s = mid + 1;
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;

    // Example input
    vector<int> nums = {1, 3, 5, 6};
    int target = 5;

    // Call the searchInsert method
    int result = sol.searchInsert(nums, target);

    // Output the result
    cout << "The target should be inserted at index: " << result << endl;

    // Test with another target
    target = 2;
    result = sol.searchInsert(nums, target);
    cout << "The target should be inserted at index: " << result << endl;

    // Test with another target
    target = 7;
    result = sol.searchInsert(nums, target);
    cout << "The target should be inserted at index: " << result << endl;

    // Test with another target
    target = 0;
    result = sol.searchInsert(nums, target);
    cout << "The target should be inserted at index: " << result << endl;

    return 0;
}
