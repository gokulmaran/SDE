#include <bits/stdc++.h>
using namespace std;
//Link: https://www.geeksforgeeks.org/problems/find-nth-root-of-m5843/1
class Solution{
public:
    // Function to check if 'mid' raised to the power of 'n' equals 'm'
    long long check(int mid, int n, int m){
        long long ans = 1;
        for(int i = 1; i <= n; i++){
            ans = ans * mid;
            if(ans > m) return 2; // If result exceeds 'm', return 2
        }
        if(ans == m) return 1; // If result equals 'm', return 1
        return 0; // Otherwise, return 0
    }

    // Function to find the nth root of m
    int NthRoot(int n, int m) {
        if(m == 0 || m == 1) {
            return m; // Handle special cases where m is 0 or 1
        }
        int s = 1, e = m;
        while(s <= e) {
            int mid = (s + e) / 2;
            long long power = check(mid, n, m);
            if(power == 1) {
                return mid; // Found the nth root
            }
            else if(power == 0) {
                s = mid + 1; // Search in the higher half
            }
            else {
                e = mid - 1; // Search in the lower half
            }
        }
        return -1; // Return -1 if the nth root does not exist
    }  
};

int main() {
    Solution sol;

    // Example test cases
    vector<pair<int, int>> testCases = {
        {2, 8},   // 2^3 = 8, so the 3rd root of 8 is 2
        {3, 27},  // 3^3 = 27, so the 3rd root of 27 is 3
        {4, 16},  // 2^4 = 16, so the 4th root of 16 is 2
        {5, 32},  // 2^5 = 32, so the 5th root of 32 is 2
        {2, 1},   // 1^2 = 1, so the 2nd root of 1 is 1
        {2, 10}   // No integer n such that n^2 = 10, so the result is -1
    };

    // Testing NthRoot function
    for (const auto& testCase : testCases) {
        int n = testCase.first;
        int m = testCase.second;
        int result = sol.NthRoot(n, m);
        cout << "The " << n << "th root of " << m << " is " << result << "." << endl;
    }

    return 0;
}
