#include <iostream>
#include <string>
#include <vector>
#include <climits>
using namespace std;
//link:https://www.geeksforgeeks.org/problems/smallest-window-containing-0-1-and-2--170637/0
class Solution {
public:
    int smallestSubstring(string s) {
        vector<int> m(3, 0);
        long long i = 0, j = 0, cnt = 0, ans = INT_MAX;
        while (j < s.size()) {
            m[s[j] - '0']++;
            if (m[s[j] - '0'] == 1) cnt++;
            while (cnt == 3) {
                ans = min(ans, j - i + 1);
                m[s[i] - '0']--;
                if (m[s[i] - '0'] <= 0) cnt--;
                i++;
            }
            j++;
        }
        return ans == INT_MAX ? -1 : ans;
    }
};

int main() {
    Solution solution;

    // Test case 1: String with digits '0', '1', and '2'
    string s1 = "001201210";
    int result1 = solution.smallestSubstring(s1);
    cout << "Smallest substring length containing '0', '1', and '2' for '" << s1 << "': " << result1 << endl;

    // Test case 2: String with repeated digits '0' and '1'
    string s2 = "0001100";
    int result2 = solution.smallestSubstring(s2);
    cout << "Smallest substring length containing '0', '1', and '2' for '" << s2 << "': " << result2 << endl;

    // Test case 3: String with all digits '0', '1', and '2' appearing multiple times
    string s3 = "012012";
    int result3 = solution.smallestSubstring(s3);
    cout << "Smallest substring length containing '0', '1', and '2' for '" << s3 << "': " << result3 << endl;

    // Test case 4: String with only '0' and '1'
    string s4 = "001011";
    int result4 = solution.smallestSubstring(s4);
    cout << "Smallest substring length containing '0', '1', and '2' for '" << s4 << "': " << result4 << endl;

    // Test case 5: String without '2'
    string s5 = "000111";
    int result5 = solution.smallestSubstring(s5);
    cout << "Smallest substring length containing '0', '1', and '2' for '" << s5 << "': " << result5 << endl;

    return 0;
}
