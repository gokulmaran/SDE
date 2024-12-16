#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//Link: https://www.geeksforgeeks.org/problems/aggressive-cows/0
class Solution {
public:
    // Function to check if it's possible to place k cows with at least 'mid' distance apart
    bool check(vector<int>& stalls, int mid, int k) {
        int last = 0; // Position of the last placed cow
        int no = 1;   // Number of cows placed
        
        for (int i = 1; i < stalls.size(); i++) {
            if (stalls[i] - stalls[last] >= mid) { // Check distance between current stall and last placed cow
                last = i; // Update position of the last placed cow
                no++;     // Increase number of cows placed
            }
        }
        return no >= k; // Return true if at least k cows are placed
    }

    // Function to find the largest minimum distance between cows
    int solve(int n, int k, vector<int>& stalls) {
        // Sort the stalls to apply binary search
        sort(stalls.begin(), stalls.end());

        int s = 1; // Start of the binary search (minimum possible distance)
        int e = stalls[n - 1] - stalls[0]; // End of the binary search (maximum possible distance)

        while (s <= e) {
            int mid = (s + e) / 2;
            if (check(stalls, mid, k)) {
                s = mid + 1; // If it's possible to place k cows with 'mid' distance, try for a larger distance
            } else {
                e = mid - 1; // Otherwise, reduce the distance
            }
        }
        return e; // Return the largest minimum distance found
    }
};

int main() {
    Solution sol;

    // Example test cases
    vector<pair<int, int>> testCases = {
        {5, 3}, // Number of stalls and cows
        {5, 3}, // Number of stalls and cows
        {5, 2}  // Number of stalls and cows
    };

    // Stalls for each test case
    vector<vector<int>> stalls = {
        {1, 2, 8, 4, 9}, // Example stall positions
        {1, 2, 4, 8, 9}, // Example stall positions
        {1, 3, 6, 7, 9}  // Example stall positions
    };

    // Test solve function
    for (int i = 0; i < testCases.size(); i++) {
        int n = testCases[i].first; // Number of stalls
        int k = testCases[i].second; // Number of cows
        vector<int> stall = stalls[i]; // Stall positions
        int result = sol.solve(n, k, stall);
        cout << "For " << n << " stalls and " << k << " cows, the largest minimum distance is " << result << "." << endl;
    }

    return 0;
}
