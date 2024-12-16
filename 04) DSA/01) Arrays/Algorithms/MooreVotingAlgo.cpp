#include <iostream>
#include <vector>

using namespace std;
//Link:https://leetcode.com/problems/majority-element/description/
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ans;
        int cnt = 0;
        int n = nums.size();

        // Apply the Boyer-Moore Voting Algorithm to find the majority element
        for (int i = 0; i < n; i++) {
            if (cnt == 0) {
                ans = nums[i];
            }
            if (ans == nums[i]) {
                cnt++;
            } else {
                cnt--;
            }
        }

        // Verify if the found element is indeed the majority element
        cnt = 0;
        for (int num : nums) {
            if (num == ans) {
                cnt++;
            }
        }

        return (cnt > n / 2) ? ans : -1; // Return -1 if no majority element exists
    }
};

int main() {
    // Example vector with a majority element
    vector<int> nums = {3, 3, 4, 2, 4, 4, 2, 4, 4};

    // Create an instance of the Solution class
    Solution sol;

    // Calling the majorityElement function to find the majority element
    int result = sol.majorityElement(nums);

    // Output the result
    cout << "The majority element is: " << result << endl;

    return 0;
}
