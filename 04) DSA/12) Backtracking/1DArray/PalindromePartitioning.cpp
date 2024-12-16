#include <iostream>
#include <vector>
#include <string>

using namespace std;
//Link: https://leetcode.com/problems/palindrome-partitioning/
class Solution {
public:
    // Helper function to check if a string is a palindrome
    bool isPali(string s) {
        int i = 0, j = s.length() - 1;
        while (i < j) {
            if (s[i++] != s[j--]) {
                return false;
            }
        }
        return true;
    }

    // Helper function to perform backtracking for partitioning the string
    void backtrack(string s, int ind, vector<vector<string>>& ans, vector<string>& res) {
        if (ind == s.length()) {
            ans.push_back(res);
            return;
        }
        for (int i = ind; i < s.length(); i++) {
            string substring = s.substr(ind, i - ind + 1);
            if (isPali(substring)) {
                res.push_back(substring);
                backtrack(s, i + 1, ans, res);
                res.pop_back();
            }
        }
    }

    // Main function to partition the string into palindromic substrings
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> res;
        backtrack(s, 0, ans, res);
        return ans;
    }
};

int main() {
    Solution solution;
    string s;

    cout << "Enter a string: ";
    cin >> s;

    vector<vector<string>> partitions = solution.partition(s);

    cout << "Palindromic partitions are:" << endl;
    for (const auto& partition : partitions) {
        cout << "[ ";
        for (const auto& str : partition) {
            cout << str << " ";
        }
        cout << "]" << endl;
    }

    return 0;
}
