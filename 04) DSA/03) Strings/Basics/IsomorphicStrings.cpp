#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;
//Link: https://leetcode.com/problems/isomorphic-strings/description/
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, int> m1, m2;
        int s1 = s.length();
        int s2 = t.length();
        if (s1 != s2) {
            return false;
        }
        // e=0, a=0
        for (int i = 0; i < s1; i++) {
            if (m1.find(s[i]) == m1.end()) {
                m1[s[i]] = i;
            }
            if (m2.find(t[i]) == m2.end()) {
                m2[t[i]] = i;
            }
            if (m1[s[i]] != m2[t[i]]) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    Solution sol;

    // Prompt the user for input
    cout << "Enter the first string: ";
    string s;
    getline(cin, s);

    cout << "Enter the second string: ";
    string t;
    getline(cin, t);

    // Call the method to check if the strings are isomorphic
    bool result = sol.isIsomorphic(s, t);

    // Output the result
    if (result) {
        cout << "The strings are isomorphic." << endl;
    } else {
        cout << "The strings are not isomorphic." << endl;
    }

    return 0;
}
