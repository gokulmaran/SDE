#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
//link: https://leetcode.com/problems/combination-sum/description/
// Helper function to find all combinations that sum up to the target
void combination(vector<int>& arr, int ind, vector<int>& res, vector<vector<int>>& ans, int target) {
    if (target <= 0) {
        if (target == 0) {
            ans.push_back(res);
        }
        return;
    }
    // Recursively find combinations
    for (int i = ind; i < arr.size(); i++) {
        res.push_back(arr[i]);
        combination(arr, i, res, ans, target - arr[i]);
        res.pop_back(); // Backtrack
    }
}

// Function to generate all combinations of numbers that sum up to the target
vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> ans;
    vector<int> res;
    sort(candidates.begin(), candidates.end()); // Sort the array to handle combinations more easily
    combination(candidates, 0, res, ans, target);
    return ans;
}

int main() {
    int n, target;
    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> candidates(n);
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> candidates[i];
    }

    cout << "Enter the target sum: ";
    cin >> target;

    vector<vector<int>> combinations = combinationSum(candidates, target);

    cout << "Combinations that sum up to " << target << " are:" << endl;
    for (const auto& comb : combinations) {
        cout << "[ ";
        for (int num : comb) {
            cout << num << " ";
        }
        cout << "]" << endl;
    }

    return 0;
}
