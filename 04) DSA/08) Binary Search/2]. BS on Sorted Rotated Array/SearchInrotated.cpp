#include <iostream>
#include <vector>
using namespace std;
//Link: https://leetcode.com/problems/search-in-rotated-sorted-array/description/
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int s = 0, e = nums.size() - 1;
        while (s <= e) {
            int mid = (s + e) / 2;
            if (nums[mid] == target) return mid;
            
            // Left half sorted
            if (nums[mid] >= nums[s]) {
                if (nums[s] <= target && target <= nums[mid]) {
                    e = mid - 1;
                } else {
                    s = mid + 1;
                }
            }
            // Right half sorted
            else {
                if (nums[mid] <= target && target <= nums[e]) {
                    s = mid + 1;
                } else {
                    e = mid - 1;
                }
            }
        }
        return -1;
    }
};

int main() {
    Solution sol;

    // Example rotated sorted array
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    
    // Target values to test
    vector<int> targets = {0, 3, 5, 7, 8};

    // Testing search function
    for (int target : targets) {
        int result = sol.search(nums, target);
        cout << "The target " << target << " is at index: " << result << endl;
    }

    return 0;
}
