#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
//link: https://leetcode.com/problems/roman-to-integer/
class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> mp = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
        int ans = 0;
        for (int i = 0; i < s.size(); i++) {
            if (i + 1 < s.size() && mp[s[i]] < mp[s[i + 1]]) {
                ans -= mp[s[i]];
            } else {
                ans += mp[s[i]];
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;

    string s;
    cout << "Enter a Roman numeral: ";
    cin >> s;

    int result = sol.romanToInt(s);

    cout << "The integer value of the Roman numeral '" << s << "' is: " << result << endl;

    return 0;
}
