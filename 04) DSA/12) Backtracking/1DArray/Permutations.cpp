#include <iostream>
#include <vector>
using namespace std;
//Link: https://leetcode.com/problems/permutations/
// Helper function for generating permutations
void backtrack(vector<int>& nums, int i, vector<vector<int>>& ans) {
    if (i >= nums.size()) {
        ans.push_back(nums);
        return;
    }
    for (int j = i; j < nums.size(); j++) {
        swap(nums[i], nums[j]);
        backtrack(nums, i + 1, ans);
        swap(nums[i], nums[j]); // Backtrack to restore the original order
    }
}

// Function to generate all permutations of the given vector
vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> ans;
    backtrack(nums, 0, ans);
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

    vector<vector<int>> permutations = permute(nums);

    cout << "All permutations are:" << endl;
    for (const auto& perm : permutations) {
        for (int num : perm) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}
