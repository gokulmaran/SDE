#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//Link: https://leetcode.com/problems/koko-eating-bananas/description/
class Solution {
public:
    // Function to calculate the total number of hours required to eat all piles with speed 'mid'
    long long totalcount(vector<int>& piles, int h, int mid) {
        long long total = 0;
        for(int i = 0; i < piles.size(); i++) {
            total += (piles[i] + mid - 1) / mid; // Equivalent to ceil(piles[i] / mid)
        }
        return total;
    }

    // Function to find the minimum eating speed
    int minEatingSpeed(vector<int>& piles, int h) {
        long long s = 1;
        long long e = *max_element(piles.begin(), piles.end());
        while(s <= e) {
            long long mid = (s + e) / 2;
            if(totalcount(piles, h, mid) <= h) {
                e = mid - 1; // Try for a smaller speed
            } else {
                s = mid + 1; // Increase speed
            }
        }
        return s; // Minimum speed that allows eating all piles within h hours
    }
};

int main() {
    Solution sol;

    // Example test cases
    vector<pair<vector<int>, int>> testCases = {
        {{3, 6, 7, 11}, 8},  // Expected output: 4
        {{30, 11, 23, 4, 20}, 5},  // Expected output: 30
        {{30, 11, 23, 4, 20}, 6},  // Expected output: 23
        {{1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, 10},  // Expected output: 10
        {{1, 1, 1, 1, 1, 1, 1, 1}, 8}  // Expected output: 1
    };

    // Testing minEatingSpeed function
    for (const auto& testCase : testCases) {
        vector<int> piles = testCase.first;
        int h = testCase.second;
        int result = sol.minEatingSpeed(piles, h);
        cout << "For piles: ";
        for (int pile : piles) {
            cout << pile << " ";
        }
        cout << "and h = " << h << ", the minimum eating speed is " << result << "." << endl;
    }

    return 0;
}
