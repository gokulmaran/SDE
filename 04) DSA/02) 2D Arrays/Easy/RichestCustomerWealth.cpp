#include <iostream>
#include <vector>

using namespace std;
//Link: https://leetcode.com/problems/richest-customer-wealth/
class Solution {
public:
    int maximumWealth(vector<vector<int>>& a) {
        int max_element = 0;

        // Iterate through each customer (row)
        for (int i = 0; i < a.size(); i++) {
            int sum = 0;

            // Sum up the wealth for the current customer
            for (int j = 0; j < a[i].size(); j++) {
                sum += a[i][j];
            }

            // Update the maximum wealth found
            if (sum > max_element) {
                max_element = sum;
            }
        }

        return max_element;
    }
};

int main() {
    // Example vector representing the wealth of customers
    vector<vector<int>> a = {
        {1, 2, 3},
        {3, 2, 1},
        {4, 5, 6}
    };

    // Create an instance of the Solution class
    Solution sol;

    // Calling the maximumWealth function to find the maximum wealth
    int result = sol.maximumWealth(a);

    // Output the result
    cout << "The maximum wealth is: " << result << endl;

    return 0;
}
