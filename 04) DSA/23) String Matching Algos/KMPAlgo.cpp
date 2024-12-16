#include <iostream>
#include <vector>
#include <string>

using namespace std;
//Link: https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/description/
class Solution {
public:
    // Function to compute the Longest Prefix Suffix (LPS) array
    void findlps(vector<int>& lps, const string& s) {
        int pre = 0;  // Length of the previous longest prefix suffix
        int suf = 1;  // Current position in the string

        // Iterate over the string to fill the LPS array
        while (suf < s.size()) {
            if (s[pre] == s[suf]) {
                // Characters match; extend the current prefix suffix length
                lps[suf] = pre + 1;
                pre++;
                suf++;
            } else {
                // Characters do not match
                if (pre == 0) {
                    // No prefix suffix match found; move to next character
                    lps[suf] = 0;
                    suf++;
                } else {
                    // Use previously computed LPS value to avoid unnecessary comparisons
                    pre = lps[pre - 1];
                }
            }
        }
    }

    // Function to find the first occurrence of 'needle' in 'haystack'
    int strStr(const string& haystack, const string& needle) {
        if (needle.empty()) return 0; // Edge case: empty needle should return 0

        // Create the LPS array for the needle
        vector<int> lps(needle.size(), 0);
        findlps(lps, needle);

        int first = 0;  // Index for the haystack
        int second = 0; // Index for the needle

        // Search for the needle in the haystack
        while (second < needle.size() && first < haystack.size()) {
            if (needle[second] == haystack[first]) {
                // Characters match; move both pointers forward
                second++;
                first++;
            } else {
                // Characters do not match
                if (second == 0) {
                    // No matching prefix; move to next character in haystack
                    first++;
                } else {
                    // Use LPS to skip unnecessary comparisons
                    second = lps[second - 1];
                }
            }
        }

        // Check if the entire needle was matched
        if (second == needle.size()) {
            return first - second; // Return the starting index of the match
        }
        return -1; // Return -1 if needle is not found
    }
};

int main() {
    Solution sol;

    // Test cases
    string haystack = "hello";
    string needle = "ll";

    // Find the first occurrence of 'needle' in 'haystack'
    int result = sol.strStr(haystack, needle);

    // Output the result
    if (result != -1) {
        cout << "Pattern found at index " << result << endl;
    } else {
        cout << "Pattern not found in text." << endl;
    }

    return 0;
}
