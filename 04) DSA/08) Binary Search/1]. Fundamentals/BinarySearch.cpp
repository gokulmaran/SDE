#include <iostream>
#include <vector>
using namespace std;
//Link: https://leetcode.com/problems/binary-search/
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int i = 0, j = nums.size() - 1;
        
        while (i <= j) {
            int mid = (i + j) / 2;
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] < target) {
                i = mid + 1;
            } else {
                j = mid - 1;
            }
        }
        return -1;
    }
};

int main() {
    Solution sol;

    // Example input
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int target = 5;

    // Call the search method
    int result = sol.search(nums, target);

    // Output the result
    cout << "The target is at index: " << result << endl;

    // Test with another target
    target = 3;
    result = sol.search(nums, target);
    cout << "The target is at index: " << result << endl;

    // Test with a target not present in the array
    target = 11;
    result = sol.search(nums, target);
    cout << "The target is at index: " << result << endl;

    // Test with another target
    target = 1;
    result = sol.search(nums, target);
    cout << "The target is at index: " << result << endl;

    // Test with the last element
    target = 10;
    result = sol.search(nums, target);
    cout << "The target is at index: " << result << endl;

    return 0;
}
