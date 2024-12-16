#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
//Link:https://leetcode.com/problems/longest-palindromic-subsequence/description/
// Function to find the length of the longest common subsequence
int LCS(string A, string B, int m, int n) {
    int t[m+1][n+1];
    for(int i=0; i<=m; i++) {
        for(int j=0; j<=n; j++) {
            if(i==0 || j==0)
                t[i][j] = 0;
            else if(A[i-1] == B[j-1])
                t[i][j] = 1 + t[i-1][j-1];
            else
                t[i][j] = max(t[i-1][j], t[i][j-1]);
        }
    }
    return t[m][n];
}

// Function to find the length of the longest palindromic subsequence
int longestPalindromeSubseq(string s) {
    string s2 = s;
    reverse(s2.begin(), s2.end());
    return LCS(s, s2, s.size(), s.size());
}

int main() {
    // Example Test Case
    string s = "bbbab";
    
    int result = longestPalindromeSubseq(s);
    cout << "Length of Longest Palindromic Subsequence: " << result << endl;
    
    return 0;
}
