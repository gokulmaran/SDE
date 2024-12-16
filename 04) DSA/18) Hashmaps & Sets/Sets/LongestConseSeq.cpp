#include <iostream>
#include <vector>
#include <set>

using namespace std;
//Link: https://leetcode.com/problems/longest-consecutive-sequence/
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;
        set<int> s;
        int ans = 1;
        for (int num : nums) {
            s.insert(num);
        }
        for (auto it = s.begin(); it != s.end(); it++) {
            int num = *it;
            if (s.find(num - 1) == s.end()) {
                int num1 = num + 1;
                while (s.find(num1) != s.end()) {
                    num1++;
                }
                ans = max(ans, num1 - num);
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;

    // Example input
    vector<int> nums = {100, 4, 200, 1, 3, 2};

    // Calculate the length of the longest consecutive sequence
    int longestConsecutiveLength = sol.longestConsecutive(nums);
    
    // Output the result
    cout << "Longest consecutive sequence length: " << longestConsecutiveLength << endl;

    return 0;
}
