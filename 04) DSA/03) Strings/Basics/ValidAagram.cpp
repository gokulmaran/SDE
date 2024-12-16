#include <iostream>
#include <string>
#include <algorithm> // For std::sort
using namespace std;
//link: https://leetcode.com/problems/valid-anagram/
class Solution {
public:
    bool isAnagram(string s, string t) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s == t;
    }
};

int main() {
    Solution sol;

    string s, t;
    cout << "Enter the first string (s): ";
    cin >> s;
    cout << "Enter the second string (t): ";
    cin >> t;

    bool result = sol.isAnagram(s, t);

    if (result) {
        cout << "The string '" << t << "' is an anagram of '" << s << "'." << endl;
    } else {
        cout << "The string '" << t << "' is NOT an anagram of '" << s << "'." << endl;
    }

    return 0;
}
