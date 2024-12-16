#include <iostream>
#include <string>

using namespace std;
//link: https://leetcode.com/problems/valid-palindrome-ii/
class Solution {
public:
    // Helper function to check if a substring is a palindrome
    bool check(string s, int i, int j) {
        while (i <= j) {
            if (s[i] != s[j]) {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }

    // Function to determine if the string can be a palindrome by removing at most one character
    bool validPalindrome(string s) {
        int i = 0, j = s.length() - 1;
        while (i < j) {
            if (s[i] != s[j]) {
                // Check both possibilities: removing s[i] or s[j]
                return check(s, i + 1, j) || check(s, i, j - 1);
            } else {
                i++;
                j--;
            }
        }
        return true; // The string is already a palindrome
    }
};

int main() {
    Solution sol;

    // Test cases
    string s1 = "abca";  // Can become a palindrome by removing 'b'
    string s2 = "racecar"; // Already a palindrome
    string s3 = "abcdef"; // Cannot become a palindrome by removing one character

    // Check if the string can be a palindrome by removing at most one character
    bool result1 = sol.validPalindrome(s1);
    bool result2 = sol.validPalindrome(s2);
    bool result3 = sol.validPalindrome(s3);

    // Output the results
    cout << "Can '" << s1 << "' be a palindrome by removing at most one character? " 
         << (result1 ? "Yes" : "No") << endl;

    cout << "Can '" << s2 << "' be a palindrome by removing at most one character? " 
         << (result2 ? "Yes" : "No") << endl;

    cout << "Can '" << s3 << "' be a palindrome by removing at most one character? " 
         << (result3 ? "Yes" : "No") << endl;

    return 0;
}
