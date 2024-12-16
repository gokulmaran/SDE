#include <iostream>
#include <vector>

using namespace std;
//Link: https://leetcode.com/problems/subsets/description/
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> subset;

        for (int sub = 0; sub < (1 << n); sub++) {
            vector<int> ans;
            for (int i = 0; i < n; i++) {
                if (sub & (1 << i)) {
                    ans.push_back(nums[i]);
                }
            }
            subset.push_back(ans);
        }

        return subset;
    }
};

void printSubsets(const vector<vector<int>>& subsets) {
    for (const auto& subset : subsets) {
        cout << "{ ";
        for (int num : subset) {
            cout << num << " ";
        }
        cout << "}" << endl;
    }
}

int main() {
    Solution sol;

    // Test case 1
    vector<int> nums1 = {1, 2, 3};
    vector<vector<int>> result1 = sol.subsets(nums1);
    cout << "Subsets of {1, 2, 3}:" << endl;
    printSubsets(result1);

    // Test case 2
    vector<int> nums2 = {0};
    vector<vector<int>> result2 = sol.subsets(nums2);
    cout << "Subsets of {0}:" << endl;
    printSubsets(result2);

    // Test case 3
    vector<int> nums3 = {5, 6, 7, 8};
    vector<vector<int>> result3 = sol.subsets(nums3);
    cout << "Subsets of {5, 6, 7, 8}:" << endl;
    printSubsets(result3);

    return 0;
}
