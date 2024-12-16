#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
//link: https://leetcode.com/problems/longest-substring-without-repeating-characters/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> m;
        int ans = 0, i = 0, j = 0, n = s.size();
        while (j < n) {
            m[s[j]]++;
            while (m[s[j]] > 1) {
                m[s[i++]]--;
            }
            ans = max(ans, j - i + 1);
            j++;
        }
        return ans;
    }
};

int main() {
    Solution solution;

    // Test case 1: General case
    string s1 = "abcabcbb";
    int result1 = solution.lengthOfLongestSubstring(s1);
    cout << "Length of longest substring without repeating characters in \"" << s1 << "\": " << result1 << endl;

    // Test case 2: String with no repeating characters
    string s2 = "abcdefg";
    int result2 = solution.lengthOfLongestSubstring(s2);
    cout << "Length of longest substring without repeating characters in \"" << s2 << "\": " << result2 << endl;

    // Test case 3: String with all repeating characters
    string s3 = "aaaaaa";
    int result3 = solution.lengthOfLongestSubstring(s3);
    cout << "Length of longest substring without repeating characters in \"" << s3 << "\": " << result3 << endl;

    // Test case 4: Empty string
    string s4 = "";
    int result4 = solution.lengthOfLongestSubstring(s4);
    cout << "Length of longest substring without repeating characters in \"" << s4 << "\": " << result4 << endl;

    // Test case 5: String with one character
    string s5 = "x";
    int result5 = solution.lengthOfLongestSubstring(s5);
    cout << "Length of longest substring without repeating characters in \"" << s5 << "\": " << result5 << endl;

    return 0;
}
