#include <iostream>
#include <string>
#include <unordered_map>
#include <limits.h>
using namespace std;
//link: https://leetcode.com/problems/minimum-window-substring/description/
class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> m; // To store the frequency of characters in t
        for (int i = 0; i < t.size(); i++) {
            m[t[i]]++;
        }
        
        int i = 0, j = 0, cnt = m.size(), start = 0, mini = INT_MAX;
        
        // Slide the window over the string s
        while (j < s.size()) {
            m[s[j]]--; // Decrease the count of the current character
            if (m[s[j]] == 0) {
                cnt--; // Decrease the count of unique characters needed
            }
            
            // Try to minimize the window
            while (cnt == 0) {
                if (j - i + 1 < mini) {
                    mini = j - i + 1;
                    start = i;
                }
                m[s[i]]++; // Increase the count of the character being excluded
                if (m[s[i]] > 0) {
                    cnt++; // Increase the count of unique characters needed
                }
                i++; // Move the left boundary of the window
            }
            j++; // Move the right boundary of the window
        }
        
        // Return the smallest window substring or an empty string if no valid window is found
        return mini == INT_MAX ? "" : s.substr(start, mini);
    }
};

int main() {
    Solution solution;

    // Test case 1: Standard case with valid window substring
    string s1 = "ADOBECODEBANC";
    string t1 = "ABC";
    cout << "Minimum window substring for \"" << s1 << "\" with t=\"" << t1 << "\" is: " << solution.minWindow(s1, t1) << endl;

    // Test case 2: t is longer than s
    string s2 = "A";
    string t2 = "AA";
    cout << "Minimum window substring for \"" << s2 << "\" with t=\"" << t2 << "\" is: " << solution.minWindow(s2, t2) << endl;

    // Test case 3: No valid window as there are no common characters
    string s3 = "A";
    string t3 = "B";
    cout << "Minimum window substring for \"" << s3 << "\" with t=\"" << t3 << "\" is: " << solution.minWindow(s3, t3) << endl;

    // Test case 4: Both s and t are empty strings
    string s4 = "";
    string t4 = "";
    cout << "Minimum window substring for \"" << s4 << "\" with t=\"" << t4 << "\" is: " << solution.minWindow(s4, t4) << endl;

    // Test case 5: s and t are identical
    string s5 = "ABC";
    string t5 = "ABC";
    cout << "Minimum window substring for \"" << s5 << "\" with t=\"" << t5 << "\" is: " << solution.minWindow(s5, t5) << endl;

    // Test case 6: No characters in common between s and t
    string s6 = "XYZ";
    string t6 = "ABC";
    cout << "Minimum window substring for \"" << s6 << "\" with t=\"" << t6 << "\" is: " << solution.minWindow(s6, t6) << endl;

    return 0;
}
