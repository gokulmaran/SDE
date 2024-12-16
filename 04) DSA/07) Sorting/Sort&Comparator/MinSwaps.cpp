#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;
//link: https://www.geeksforgeeks.org/problems/minimum-swaps/1
class Solution {
public:
    // Function to find the minimum number of swaps required to sort the array
    int minSwaps(vector<int>& nums) {
        vector<int> ans(nums.begin(), nums.end());
        sort(ans.begin(), ans.end());
        unordered_map<int, int> mp;
        for (int i = 0; i < ans.size(); i++) {
            mp[ans[i]] = i;
        }
        int count = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (mp[nums[i]] != i) {
                swap(nums[i], nums[mp[nums[i]]]);
                count++;
                i--;
            }
        }
        return count;
    }
};

int main() {
    Solution sol;

    // Example input
    vector<int> nums = {4, 3, 2, 1};

    // Call the minSwaps method
    int result = sol.minSwaps(nums);

    // Output the result
    cout << "Minimum number of swaps required: " << result << endl;

    return 0;
}
