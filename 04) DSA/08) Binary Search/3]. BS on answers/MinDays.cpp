#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
//Link: https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/
class Solution {
public:
    // Function to determine how many bouquets can be made with the given number of days
    int solve(int mid, vector<int>& bloomDay, int k) {
        int cnt = 0;  // Count of consecutive flowers that have bloomed
        int total = 0;  // Total number of bouquets made
        for (int i = 0; i < bloomDay.size(); i++) {
            if (mid >= bloomDay[i]) {
                cnt++;
                if (cnt == k) {
                    total++;
                    cnt = 0;  // Reset count for the next bouquet
                }
            } else {
                cnt = 0;  // Reset count if the current flower hasn't bloomed yet
            }
        }
        return total;
    }

    // Function to find the minimum number of days to make at least 'm' bouquets
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        if (m > n / k) return -1;  // Not enough flowers to make 'm' bouquets

        int i = 1, j = INT_MIN;
        for (int x : bloomDay) {
            j = max(j, x);
        }

        int mid;
        int ans = INT_MAX;
        while (i <= j) {
            mid = (i + j) / 2;
            if (solve(mid, bloomDay, k) >= m) {
                ans = min(ans, mid);
                j = mid - 1;
            } else {
                i = mid + 1;
            }
        }
        return i;
    }
};

int main() {
    Solution sol;

    // Example test cases
    vector<pair<vector<int>, pair<int, int>>> testCases = {
        {{1, 10, 3, 10, 2}, {3, 1}},  // Expected output: 3
        {{1, 10, 3, 10, 2}, {3, 2}},  // Expected output: 10
        {{1, 10, 3, 10, 2}, {2, 2}},  // Expected output: 3
        {{7, 7, 7, 7, 7, 7, 7}, {5, 3}},  // Expected output: 7
        {{1, 2, 3, 4, 5, 6, 7}, {3, 2}}  // Expected output: 4
    };

    // Testing minDays function
    for (const auto& testCase : testCases) {
        vector<int> bloomDay = testCase.first;
        int m = testCase.second.first;
        int k = testCase.second.second;
        int result = sol.minDays(bloomDay, m, k);
        cout << "For bloomDay: ";
        for (int day : bloomDay) {
            cout << day << " ";
        }
        cout << "with m = " << m << " and k = " << k << ", the minimum number of days is " << result << "." << endl;
    }

    return 0;
}
