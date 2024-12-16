#include <iostream>
#include <string>
#include <vector>
#include <algorithm>  // for max function
using namespace std;
//link: https://www.geeksforgeeks.org/problems/length-of-the-longest-substring3036/1
class Solution {
public:
    int longestUniqueSubsttr(string s) {
        vector<int> m(26, 0); // frequency of each character
        int i = 0, j = 0, ans = 0;
        while (j < s.size()) {
            m[s[j] - 'a']++;
            if (m[s[j] - 'a'] == 1) {
                ans = max(ans, j - i + 1); // update the maximum length
            }
            while (m[s[j] - 'a'] > 1 && i <= j) {
                m[s[i] - 'a']--;
                i++;
            }
            j++;
        }
        return ans;
    }
};

int main() {
    Solution solution;

    // Test case 1: String with unique characters
    string s1 = "abcabcbb";
    int result1 = solution.longestUniqueSubsttr(s1);
    cout << "Longest unique substring length for '" << s1 << "': " << result1 << endl;

    // Test case 2: String with all characters the same
    string s2 = "bbbb";
    int result2 = solution.longestUniqueSubsttr(s2);
    cout << "Longest unique substring length for '" << s2 << "': " << result2 << endl;

    // Test case 3: String with no repeating characters
    string s3 = "abcdefg";
    int result3 = solution.longestUniqueSubsttr(s3);
    cout << "Longest unique substring length for '" << s3 << "': " << result3 << endl;

    // Test case 4: String with mixed characters
    string s4 = "pwwkew";
    int result4 = solution.longestUniqueSubsttr(s4);
    cout << "Longest unique substring length for '" << s4 << "': " << result4 << endl;

    // Test case 5: Empty string
    string s5 = "";
    int result5 = solution.longestUniqueSubsttr(s5);
    cout << "Longest unique substring length for '" << s5 << "': " << result5 << endl;

    return 0;
}
