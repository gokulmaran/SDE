#include <iostream>
#include <vector>

using namespace std;
//Link:https://www.geeksforgeeks.org/problems/subset-sum-problem-1611555638/1

// Recursive helper function with memoization
bool solve(int i, int n, const vector<int>& arr, int sum, vector<vector<int>>& dp) {
    if (sum == 0) return true;  // Base case: If sum is 0, subset is found
    if (i == n) return false;   // Base case: If we have considered all elements, no valid subset found
    if (dp[i][sum] != -1) return dp[i][sum]; // Return result if already computed

    bool notPick = solve(i + 1, n, arr, sum, dp); // Option to not pick the current element
    bool pick = false;
    if (arr[i] <= sum) {
        pick = solve(i + 1, n, arr, sum - arr[i], dp); // Option to pick the current element
    }
    
    // Store result in dp table
    return dp[i][sum] = (pick || notPick);
}

// Main function to check if there's a subset with the given sum
bool isSubsetSum(const vector<int>& arr, int sum) {
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(sum + 1, -1)); // Initialize dp table with -1
    return solve(0, n, arr, sum, dp); // Start solving from index 0
}

// Main function to test the isSubsetSum function
int main() {
    // Example input
    vector<int> arr = {3, 34, 4, 12, 5, 2};
    int sum = 9;

    // Call the function and get the result
    bool result = isSubsetSum(arr, sum);

    // Output the result
    if (result) {
        cout << "There is a subset with the given sum." << endl;
    } else {
        cout << "There is no subset with the given sum." << endl;
    }

    return 0;
}
