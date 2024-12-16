#include <iostream>
#include <vector>
#include <string>

using namespace std;
//Link: https://leetcode.com/problems/generate-parentheses/
// Helper function to recursively generate all combinations of valid parentheses
void recurse(vector<string>& output, string s, int open, int close, int n) {
    if (open == n && close == n) {
        output.push_back(s);
        return;
    }
    if (open < n) {
        recurse(output, s + "(", open + 1, close, n);
    }
    if (close < open) {
        recurse(output, s + ")", open, close + 1, n);
    }
}

// Function to generate all combinations of valid parentheses
vector<string> generateParenthesis(int n) {
    vector<string> output;
    recurse(output, "", 0, 0, n);
    return output;
}

int main() {
    int n;
    cout << "Enter the number of pairs of parentheses: ";
    cin >> n;

    vector<string> result = generateParenthesis(n);

    cout << "Generated parentheses combinations are:" << endl;
    for (const string& s : result) {
        cout << s << endl;
    }

    return 0;
}
