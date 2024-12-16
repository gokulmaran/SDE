#include <iostream>
#include <vector>

using namespace std;
//Tabulation
//Link:https://www.geeksforgeeks.org/problems/subset-sum-problem-1611555638/1
// Implementation of isSubsetSum function
bool isSubsetSum(vector<int> arr, int tar) {
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(tar + 1, 0));

    // Base case: A subset with sum 0 is always possible (empty subset)
    for (int i = 0; i < n; i++) dp[i][0] = 1;

    // Base case: If the first element is less than or equal to target, we can form a subset with that element
    if (arr[0] <= tar) dp[0][arr[0]] = 1;

    // Fill the DP table
    for (int ind = 1; ind < n; ind++) {
        for (int sum = 1; sum <= tar; sum++) {
            bool notTake = dp[ind - 1][sum];
            bool take = false;
            if (arr[ind] <= sum) take = dp[ind - 1][sum - arr[ind]];

            dp[ind][sum] = take || notTake;
        }
    }
    return dp[n - 1][tar];
}

int main() {
    // Example array and target sum
    vector<int> arr = {3, 34, 4, 12, 5, 2};
    int tar = 9;

    // Call the isSubsetSum function and print the result
    bool result = isSubsetSum(arr, tar);

    if (result) {
        cout << "There is a subset with sum " << tar << endl;
    } else {
        cout << "No subset with sum " << tar << endl;
    }

    return 0;
}


