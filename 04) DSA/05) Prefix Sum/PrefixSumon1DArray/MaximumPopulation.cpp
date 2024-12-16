#include <iostream>
#include <vector>

using namespace std;
//link: https://leetcode.com/problems/maximum-population-year/
class Solution {
public:
    // Function to find the year with the maximum population
    int maximumPopulation(vector<vector<int>>& logs) {
        // Array to keep track of population changes
        int pop[2051] = {};  // Initialize all years to 0

        // Process each log entry to update population changes
        for (auto &l : logs) {
            ++pop[l[0]];
            --pop[l[1]];
        }

        // Variable to keep track of the year with the maximum population
        int res = 0;
        int currentPopulation = 0;

        // Calculate the population for each year from 1950 to 2049
        for (int i = 1950; i < 2050; i++) {
            currentPopulation += pop[i];
            if (currentPopulation > pop[res]) {
                res = i;
            }
        }

        return res;
    }
};

int main() {
    Solution sol;

    // Test case 1
    vector<vector<int>> logs1 = {
        {1993, 2001},
        {2000, 2010},
        {2010, 2015}
    };

    cout << "Year with the maximum population for test case 1: " 
         << sol.maximumPopulation(logs1) << endl; // Expected output: 2000

    // Test case 2
    vector<vector<int>> logs2 = {
        {1950, 1960},
        {1960, 1970},
        {1970, 1980},
        {1980, 1990},
        {1990, 2000}
    };

    cout << "Year with the maximum population for test case 2: " 
         << sol.maximumPopulation(logs2) << endl; // Expected output: 1960

    return 0;
}
