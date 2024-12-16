#include <bits/stdc++.h>
using namespace std;
//Link: https://www.naukri.com/code360/problems/min-steps-to-one-using-dp_920548?leftPanelTabValue=PROBLEM
// Function to compute the minimum number of steps to reduce n to 1
int countStepsToOne(int n) {
    vector<int> dp(n + 1, 0);
    dp[0] = 0;
    dp[1] = 0;
    dp[2] = 1;
    dp[3] = 1;

    for (int i = 4; i <= n; i++) {
        int a = dp[i - 1] + 1;
        int b = INT_MAX;
        if (i % 2 == 0) {
            b = dp[i / 2] + 1;
        }
        int c = INT_MAX;
        if (i % 3 == 0) {
            c = dp[i / 3] + 1;
        }
        dp[i] = min(a, min(b, c));
    }

    return dp[n];
}

int main() {
    int n;

    // Input the value of n
    cout << "Enter the value of n: ";
    cin >> n;

    // Check if the input is valid
    if (n <= 0) {
        cout << "n should be a positive integer." << endl;
        return 1;  // Return an error code
    }

    // Compute the minimum number of steps to reduce n to 1
    int result = countStepsToOne(n);

    // Output the result
    cout << "Minimum steps to reduce " << n << " to 1: " << result << endl;

    return 0;
}
