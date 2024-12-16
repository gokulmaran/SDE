#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;
//Link: https://leetcode.com/problems/burst-balloons/description/
class Solution {
public:
    int MCM(vector<int>& nums, int left, int right, vector<vector<int>>& mem) {
        if (left >= right) // Invalid condition
            return 0;
        
        if (mem[left][right] != -1)
            return mem[left][right];
        
        int max_cost = INT_MIN;
        
        for (int k = left; k < right; k++) {
            int total_cost = MCM(nums, left, k, mem) + MCM(nums, k + 1, right, mem) + nums[left - 1] * nums[k] * nums[right];
            max_cost = max(max_cost, total_cost);
        }
        
        mem[left][right] = max_cost;
        return mem[left][right];
    }
    
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(), 1); // Insert 1 at the beginning of the vector
        nums.push_back(1); // Insert 1 at the end of the vector
        
        int n = nums.size();
        vector<vector<int>> mem(n, vector<int>(n, -1));
        
        return MCM(nums, 1, n - 1, mem);
    }
};

int main() {
    Solution solution;
    
    // Example input
    vector<int> nums = {3, 1, 5, 8}; // The numbers in the balloons array
    
    // Call the maxCoins function
    int result = solution.maxCoins(nums);
    
    // Output the result
    cout << "Maximum coins that can be obtained: " << result << endl;
    
    return 0;
}
