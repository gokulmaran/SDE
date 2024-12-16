#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;
//Link: https://leetcode.com/problems/remove-duplicates-from-sorted-array/
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        set<int> s(nums.begin(), nums.end());
        copy(s.begin(), s.end(), nums.begin());
        return s.size();
    }
};

int main() {
    Solution sol;

    // Example input with duplicates
    vector<int> nums = {1, 1, 2, 3, 3, 4, 4, 5};

    // Call the removeDuplicates method
    int uniqueCount = sol.removeDuplicates(nums);
    
    // Output the result
    cout << "Number of unique elements: " << uniqueCount << endl;
    cout << "Unique elements in the vector: ";
    for (int i = 0; i < uniqueCount; ++i) {
        cout << nums[i] << " ";
    }
    cout << endl;

    return 0;
}
