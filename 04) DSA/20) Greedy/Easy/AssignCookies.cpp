#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
//Link: https://leetcode.com/problems/assign-cookies/
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        // Sort the greed factor and the size of cookies
        sort(s.begin(), s.end());
        sort(g.begin(), g.end());

        // Initialize pointers and count
        int cnt = 0, i = 0, j = 0;

        // Traverse the cookies and the children
        while (i < s.size() && j < g.size()) {
            if (g[j] <= s[i]) {
                cnt++;
                j++;
            }
            i++;
        }
        return cnt;
    }
};

int main() {
    Solution solution;

    // Example input
    vector<int> g = {1, 2, 3}; // Greed factors of children
    vector<int> s = {1, 1};    // Sizes of cookies

    // Get the result from the solution
    int result = solution.findContentChildren(g, s);

    // Output the result
    cout << "The maximum number of content children is: " << result << endl;

    return 0;
}
