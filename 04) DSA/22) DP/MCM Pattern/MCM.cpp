#include <iostream>
#include <vector>
#include <climits> // For INT_MAX

using namespace std;
//Link: https://www.geeksforgeeks.org/problems/matrix-chain-multiplication0303/1
class Solution {
public:
    // Memoization version
    int Memo(int i, int j, int arr[], vector<vector<int>>& dp) {
        if (i >= j) {
            return 0;
        }
        if (dp[i][j] != -1) return dp[i][j];
        
        int mini = INT_MAX;
        for (int k = i; k < j; k++) {
            int temp = Memo(i, k, arr, dp) + Memo(k + 1, j, arr, dp) + arr[i - 1] * arr[k] * arr[j];
            mini = min(temp, mini);
        }
        return dp[i][j] = mini;
    }
    
    int matrixMultiplicationMemo(int N, int arr[]) {
        vector<vector<int>> dp(N + 1, vector<int>(N + 1, -1));
        return Memo(1, N - 1, arr, dp);
    }

    // Tabulation version
    int matrixMultiplicationTabulation(int N, int arr[]) {
        vector<vector<int>> dp(N, vector<int>(N, 0));
        
        // l is chain length.
        for (int l = 2; l < N; l++) { // l = 2 means subproblem size of 2
            for (int i = 1; i < N - l + 1; i++) {
                int j = i + l - 1;
                dp[i][j] = INT_MAX;
                for (int k = i; k < j; k++) {
                    int cost = dp[i][k] + dp[k + 1][j] + arr[i - 1] * arr[k] * arr[j];
                    dp[i][j] = min(dp[i][j], cost);
                }
            }
        }
        
        return dp[1][N - 1];
    }
};

int main() {
    Solution solution;
    int arr[] = {10, 20, 30, 40, 30}; // Example dimensions
    int N = sizeof(arr) / sizeof(arr[0]);

    // Test memoization version
    int resultMemo = solution.matrixMultiplicationMemo(N, arr);
    cout << "Minimum number of multiplications (Memoization) is: " << resultMemo << endl;

    // Test tabulation version
    int resultTabulation = solution.matrixMultiplicationTabulation(N, arr);
    cout << "Minimum number of multiplications (Tabulation) is: " << resultTabulation << endl;

    return 0;
}
