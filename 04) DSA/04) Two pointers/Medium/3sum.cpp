#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
//link: https://leetcode.com/problems/3sum/description/
class Solution {
public:
    // Function to find all unique triplets in the array that sum to zero
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        
        sort(nums.begin(), nums.end()); // Sort the array
        
        for (int i = 0; i < nums.size(); i++) {
            // Skip duplicate elements
            if (i != 0 && nums[i] == nums[i - 1]) continue;

            int j = i + 1;
            int k = nums.size() - 1;

            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                
                if (sum < 0) {
                    j++;
                } else if (sum > 0) {
                    k--;
                } else {
                    ans.push_back({nums[i], nums[j], nums[k]});
                    j++;
                    k--;
                    // Skip duplicate elements
                    while (j < k && nums[j] == nums[j - 1]) j++;
                    while (j < k && nums[k] == nums[k + 1]) k--;
                }
            }
        }
        
        return ans;
    }
};

int main() {
    Solution sol;

    // Test case 1
    vector<int> nums1 = {-1, 0, 1, 2, -1, -4};

    // Test case 2
    vector<int> nums2 = {0, 0, 0, 0};

    // Find all unique triplets that sum to zero
    vector<vector<int>> result1 = sol.threeSum(nums1);
    vector<vector<int>> result2 = sol.threeSum(nums2);

    // Output the results
    cout << "Triplets that sum to zero (test case 1):" << endl;
    for (const auto& triplet : result1) {
        cout << "{ ";
        for (const auto& num : triplet) {
            cout << num << " ";
        }
        cout << "}" << endl;
    }

    cout << "Triplets that sum to zero (test case 2):" << endl;
    for (const auto& triplet : result2) {
        cout << "{ ";
        for (const auto& num : triplet) {
            cout << num << " ";
        }
        cout << "}" << endl;
    }

    return 0;
}
