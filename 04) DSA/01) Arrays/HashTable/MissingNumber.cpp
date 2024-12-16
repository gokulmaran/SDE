#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
//Link: https://leetcode.com/problems/missing-number/description/
class Solution {
public:
    int findSmallestMissingNonNegative(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mp;

        // Count the occurrences of each number
        for (int i = 0; i < n; i++) {
            mp[nums[i]]++;
        }

        // Find the smallest non-negative integer not present in the array
        for (int i = 0; i <= n; i++) {
            if (mp[i] == 0) {
                return i;
            }
        }

        // In case all values from 0 to n are present, return n
        return n;
    }
};

int main() {
    // Example vector with integers
    vector<int> nums = {3, 0, 1};

    // Create an instance of the Solution class
    Solution sol;

    // Calling the findSmallestMissingNonNegative function to find the smallest missing non-negative integer
    int result = sol.findSmallestMissingNonNegative(nums);

    // Output the result
    cout << "The smallest missing non-negative integer is: " << result << endl;

    return 0;
}
