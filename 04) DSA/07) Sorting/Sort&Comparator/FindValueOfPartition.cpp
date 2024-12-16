#include <iostream>
#include <vector>
#include <algorithm>
#include <climits> // for INT_MAX
using namespace std;
//Link: https://leetcode.com/problems/find-the-value-of-the-partition/
class Solution {
public:
    int findValueOfPartition(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int ans = INT_MAX;
        for (int i = 1; i < nums.size(); i++) {
            ans = min(ans, abs(nums[i] - nums[i - 1]));
        }
        return ans;
    }
};

int main() {
    Solution sol;

    // Example input
    vector<int> nums = {4, 2, 1, 3, 5};

    // Call the findValueOfPartition method
    int result = sol.findValueOfPartition(nums);

    // Output the result
    cout << "The minimum value of the partition is: " << result << endl;

    return 0;
}
