#include <iostream>
#include <string>
#include <unordered_map>
#include <set>
#include <climits>

using namespace std;
//link: https://www.geeksforgeeks.org/problems/smallest-distant-window3132/1
class Solution {
public:
    int findSubString(string str) {
        int ans = INT_MAX;
        set<char> s(str.begin(), str.end()); // Set of distinct characters in the string
        unordered_map<char, int> m; // Map to count frequency of characters in the current window
        int i = 0, j = 0;
        
        while (j < str.size()) {
            m[str[j]]++;
            while (m.size() == s.size()) {
                ans = min(ans, j - i + 1);
                m[str[i]]--;
                if (m[str[i]] == 0) {
                    m.erase(str[i]);
                }
                i++;
            }
            j++;
        }
        
        return ans == INT_MAX ? -1 : ans;
    }
};

int main() {
    Solution solution;

    // Test case 1
    string str1 = "adobecodebanc";
    int result1 = solution.findSubString(str1);
    cout << "Shortest substring length containing all distinct characters for '" << str1 << "': " << result1 << endl;

    // Test case 2
    string str2 = "aabbcc";
    int result2 = solution.findSubString(str2);
    cout << "Shortest substring length containing all distinct characters for '" << str2 << "': " << result2 << endl;

    // Test case 3
    string str3 = "abc";
    int result3 = solution.findSubString(str3);
    cout << "Shortest substring length containing all distinct characters for '" << str3 << "': " << result3 << endl;

    // Test case 4
    string str4 = "aaa";
    int result4 = solution.findSubString(str4);
    cout << "Shortest substring length containing all distinct characters for '" << str4 << "': " << result4 << endl;

    // Test case 5
    string str5 = "abcabcbb";
    int result5 = solution.findSubString(str5);
    cout << "Shortest substring length containing all distinct characters for '" << str5 << "': " << result5 << endl;

    return 0;
}
