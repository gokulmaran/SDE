#include <iostream>
#include <vector>
using namespace std;
//Link; https://leetcode.com/problems/subsets/
// Helper function to generate all subsets
void subset(vector<int>& nums, int ind, vector<vector<int>>& ans, vector<int>& res) {
    if (ind == nums.size()) {
        ans.push_back(res);
        return;
    }
    
    // Include the current element
    res.push_back(nums[ind]);
    subset(nums, ind + 1, ans, res);

    // Exclude the current element
    res.pop_back();
    subset(nums, ind + 1, ans, res);
}

// Function to generate all subsets of the given vector
vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> ans;
    vector<int> res;
    subset(nums, 0, ans, res);
    return ans;
}

int main() {
    int size;
    cout << "Enter the number of elements: ";
    cin >> size;

    vector<int> nums(size);
    cout << "Enter the elements: ";
    for (int i = 0; i < size; i++) {
        cin >> nums[i];
    }

    vector<vector<int>> allSubsets = subsets(nums);

    cout << "All subsets are:" << endl;
    for (const auto& subset : allSubsets) {
        cout << "[ ";
        for (int num : subset) {
            cout << num << " ";
        }
        cout << "]" << endl;
    }

    return 0;
}
