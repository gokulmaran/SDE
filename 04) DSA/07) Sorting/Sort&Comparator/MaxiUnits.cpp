#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//Link: https://leetcode.com/problems/maximum-units-on-a-truck/
class Solution {
public:
    // Comparator function to sort based on the number of units in descending order
    static bool cmp(const vector<int>& a, const vector<int>& b) {
        return a[1] > b[1];
    }

    // Function to calculate the maximum units that can be packed into k boxes
    int maximumUnits(vector<vector<int>>& a, int k) {
        int ans = 0;
        sort(a.begin(), a.end(), cmp);
        for (int i = 0; i < a.size(); i++) {
            int take = min(k, a[i][0]);
            ans += take * (a[i][1]);
            k -= take;
            if (k == 0) {
                break;
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;

    // Example input
    vector<vector<int>> a = {{1, 3}, {2, 2}, {3, 1}};
    int k = 4;

    // Call the maximumUnits method
    int result = sol.maximumUnits(a, k);

    // Output the result
    cout << "Maximum units that can be packed: " << result << endl;

    return 0;
}
