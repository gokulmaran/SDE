#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
//Link:https://leetcode.com/problems/combination-sum-ii/description/
// Global result vector to store all unique combinations
vector<vector<int>> res;

// Helper function for backtracking to find combinations
void backtrack(vector<int>& a, int target, vector<int>& ans, int idx) {
    if (target <= 0) {
        if (target == 0) {
            res.push_back(ans);
        }
        return;
    }
    for (int i = idx; i < a.size(); i++) {
        if (a[i] > target) break;
        if (i > idx && a[i] == a[i - 1]) continue; // Skip duplicates
        ans.push_back(a[i]);
        backtrack(a, target - a[i], ans, i + 1);
        ans.pop_back();
    }
}

// Function to find all unique combinations that sum up to the target
vector<vector<int>> combinationSum2(vector<int>& arr, int target) {
    vector<int> ans;
    sort(arr.begin(), arr.end()); // Sort the array to handle duplicates
    backtrack(arr, target, ans, 0);
    return res;
}

int main() {
    int n, target;
    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Enter the target sum: ";
    cin >> target;

    vector<vector<int>> combinations = combinationSum2(arr, target);

    cout << "Unique combinations that sum up to " << target << " are:" << endl;
    for (const auto& comb : combinations) {
        cout << "[ ";
        for (int num : comb) {
            cout << num << " ";
        }
        cout << "]" << endl;
    }

    return 0;
}
