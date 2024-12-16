#include <iostream>
#include <vector>
#include <string>

using namespace std;
//Link:https://leetcode.com/problems/shortest-palindrome/description/
class Solution {
public:
    // Function to compute the Longest Prefix Suffix (LPS) array
    void computelps(vector<int>& lps, const string& s, int m) {
        int len = 0; // Length of the previous longest prefix suffix
        int i = 1;   // Current position in the string

        // Compute the LPS array
        while (i < m) {
            if (s[len] == s[i]) {
                len++;
                lps[i] = len;
                i++;
            } else {
                if (len != 0) {
                    len = lps[len - 1]; // Use previous LPS value
                } else {
                    lps[i] = 0;
                    i++;
                }
            }
        }
    }

    // Function to find the shortest palindrome by adding characters to the front
    string shortestPalindrome(string s) {
        int n = s.size();
        string ans = s;
        s += '#'; // Separator to avoid overlap

        // Create the reverse of the string and append it to the original string
        for (int i = n - 1; i >= 0; i--) {
            s += s[i];
        }

        // Create the LPS array for the concatenated string
        vector<int> lps(2 * n + 2, 0);
        computelps(lps, s, n + n + 1);

        // Form the shortest palindrome
        string temp = "";
        for (int i = n - 1; i >= lps[2 * n]; i--) {
            temp += s[i];
        }
        return temp + ans;
    }
};

int main() {
    Solution sol;

    // Test cases
    string s1 = "aacecaaa";
    string s2 = "abcd";

    // Find the shortest palindrome for each test case
    string result1 = sol.shortestPalindrome(s1);
    string result2 = sol.shortestPalindrome(s2);

    // Output the results
    cout << "Shortest palindrome for '" << s1 << "' is: " << result1 << endl;
    cout << "Shortest palindrome for '" << s2 << "' is: " << result2 << endl;

    return 0;
}
