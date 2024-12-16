#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;
//link: https://leetcode.com/problems/longest-repeating-character-replacement/description/
class Solution {
public:
    int characterReplacement(string s, int k) {
        int i = 0, j = 0, ans = -1, maxi = 0;
        unordered_map<char, int> m;
        while (j < s.size()) {
            m[s[j]]++;
            maxi = max(maxi, m[s[j]]);
            while ((j - i + 1) - maxi > k) {
                m[s[i]]--;
                i++;
            }
            ans = max(ans, j - i + 1);
            j++;
        }
        return ans;
    }
};

int main() {
    Solution solution;

    // Test case 1: Replace characters to form the longest substring
    string s1 = "ABAB";
    int k1 = 2;
    cout << "Longest substring after replacements for \"" << s1 << "\" with k=" << k1 << " is: " << solution.characterReplacement(s1, k1) << endl;

    // Test case 2: Only one type of character already present
    string s2 = "AABABBA";
    int k2 = 1;
    cout << "Longest substring after replacements for \"" << s2 << "\" with k=" << k2 << " is: " << solution.characterReplacement(s2, k2) << endl;

    // Test case 3: All characters are different
    string s3 = "ABCDE";
    int k3 = 2;
    cout << "Longest substring after replacements for \"" << s3 << "\" with k=" << k3 << " is: " << solution.characterReplacement(s3, k3) << endl;

    // Test case 4: Large value of k
    string s4 = "AABBAA";
    int k4 = 10;
    cout << "Longest substring after replacements for \"" << s4 << "\" with k=" << k4 << " is: " << solution.characterReplacement(s4, k4) << endl;

    // Test case 5: No replacements needed
    string s5 = "AAA";
    int k5 = 0;
    cout << "Longest substring after replacements for \"" << s5 << "\" with k=" << k5 << " is: " << solution.characterReplacement(s5, k5) << endl;

    // Test case 6: Empty string
    string s6 = "";
    int k6 = 3;
    cout << "Longest substring after replacements for \"" << s6 << "\" with k=" << k6 << " is: " << solution.characterReplacement(s6, k6) << endl;

    return 0;
}
