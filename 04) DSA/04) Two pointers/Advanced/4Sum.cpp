#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;
//link: https://leetcode.com/problems/4sum/description/
class Solution {
public:
    // Function to find all unique quadruplets that sum up to the target
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end()); // Sort the array
        set<vector<int>> s; // To store unique quadruplets
        vector<vector<int>> output; // To store the final result

        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                int k = j + 1;
                int l = nums.size() - 1;
                while (k < l) {
                    long long int sum = nums[i];
                    sum += nums[j];
                    sum += nums[k];
                    sum += nums[l];
                    if (sum == target) {
                        s.insert({nums[i], nums[j], nums[k], nums[l]});
                        k++;
                        l--;
                    } else if (sum < target) {
                        k++;
                    } else {
                        l--;
                    }
                }
            }
        }

        // Convert set to vector
        for (auto quadruplets : s) {
            output.push_back(quadruplets);
        }

        return output; // Return the result
    }
};

int main() {
    Solution sol;

    // Test case 1
    vector<int> nums1 = {1, 0, -1, 0, -2, 2};
    int target1 = 0;

    // Test case 2
    vector<int> nums2 = {2, 2, 2, 2, 2};
    int target2 = 8;

    // Find all unique quadruplets that sum up to the target
    vector<vector<int>> result1 = sol.fourSum(nums1, target1);
    vector<vector<int>> result2 = sol.fourSum(nums2, target2);

    // Output the results
    cout << "Test case 1:" << endl;
    for (const auto& quad : result1) {
        cout << "[";
        for (const auto& num : quad) {
            cout << num << " ";
        }
        cout << "]" << endl;
    }

    cout << "Test case 2:" << endl;
    for (const auto& quad : result2) {
        cout << "[";
        for (const auto& num : quad) {
            cout << num << " ";
        }
        cout << "]" << endl;
    }

    return 0;
}
