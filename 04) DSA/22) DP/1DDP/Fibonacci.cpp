#include <iostream>
using namespace std;
//Link: https://leetcode.com/problems/fibonacci-number/description/
// Function to compute the N-th Fibonacci number
int fib(int N) {
    if (N < 2) {
        return N;
    }
    int dp[N + 1];
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i <= N; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[N];
}

int main() {
    int N;

    // Input the value of N
    cout << "Enter the value of N: ";
    cin >> N;

    // Check if the input is valid
    if (N < 0) {
        cout << "N should be a non-negative integer." << endl;
        return 1;  // Return an error code
    }

    // Compute the N-th Fibonacci number
    int result = fib(N);

    // Output the result
    cout << "Fibonacci number F(" << N << ") is: " << result << endl;

    return 0;
}
