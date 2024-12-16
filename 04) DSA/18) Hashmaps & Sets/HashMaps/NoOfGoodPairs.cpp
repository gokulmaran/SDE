#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
//Link:https://leetcode.com/problems/number-of-good-pairs/
class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int ans = 0;
        unordered_map<int, int> m;
        for (auto x : nums) {
            ans += m[x]++;
        }
        return ans;
    }
};

int main() {
    Solution sol;

    // Example input
    vector<int> nums = {1, 2, 3, 1, 1, 3};

    // Calculate the number of good pairs
    int result = sol.numIdenticalPairs(nums);

    // Output the result
    cout << "Number of good pairs: " << result << endl;

    return 0;
}
