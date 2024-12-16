#include <iostream>
#include <string>
using namespace std;
//Link: https://leetcode.com/problems/rotate-string/description/
class Solution {
public:
    bool rotateString(string s, string goal) {
        if (s.size() != goal.size()) {
            return false;
        }
        return (s + s).find(goal) != string::npos;
    }
};

int main() {
    Solution sol;

    string s, goal;
    cout << "Enter the first string (s): ";
    cin >> s;
    cout << "Enter the second string (goal): ";
    cin >> goal;

    bool result = sol.rotateString(s, goal);

    if (result) {
        cout << "The string '" << goal << "' is a rotation of '" << s << "'." << endl;
    } else {
        cout << "The string '" << goal << "' is NOT a rotation of '" << s << "'." << endl;
    }

    return 0;
}
