#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
//Link:https://leetcode.com/problems/find-all-duplicates-in-an-array/description/
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;
        unordered_map<int, int> mp;

        // Count occurrences of each number
        for (int i : nums) {
            // Increment count and check if it exceeds 1 (indicating a duplicate)
            if (++mp[i] > 1) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};

int main() {
    // Example vector with duplicate elements
    vector<int> nums = {4, 3, 2, 7, 8, 2, 1, 7};

    // Create an instance of the Solution class
    Solution sol;

    // Calling the findDuplicates function to find duplicates in the array
    vector<int> duplicates = sol.findDuplicates(nums);

    // Output the duplicate elements
    cout << "Duplicate elements are: ";
    for (int num : duplicates) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
