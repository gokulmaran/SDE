#include <iostream>
#include <string>
using namespace std;
//Link: https://leetcode.com/problems/largest-odd-number-in-string/description/
class Solution {
public:
    string largestOddNumber(string num) {
        int i = 0;
        for (int j = num.size() - 1; j >= 0; j--) {
            if ((num[j] - '0') % 2 != 0) {
                return num.substr(i, j - i + 1);
            }
        }
        return "";
    }
};

int main() {
    Solution sol;

    string num;
    cout << "Enter the number as a string: ";
    cin >> num;

    string result = sol.largestOddNumber(num);

    if (result.empty()) {
        cout << "No odd number can be formed." << endl;
    } else {
        cout << "The largest odd number that can be formed is: " << result << endl;
    }

    return 0;
}
