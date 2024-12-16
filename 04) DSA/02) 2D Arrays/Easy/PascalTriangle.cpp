#include <iostream>
#include <vector>

using namespace std;
//Link: 
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if (numRows == 0) {
            return {};
        }
        vector<vector<int>> ans = generate(numRows - 1); // Recursive call to generate the previous rows
        vector<int> res(numRows, 1); // Initialize the current row with all 1's
        
        // Compute the values for the current row
        for (int i = 1; i < numRows - 1; i++) {
            res[i] = ans.back()[i - 1] + ans.back()[i];
        }
        ans.push_back(res); // Add the current row to the result
        return ans;
    }
};

int main() {
    // Number of rows to generate
    int numRows = 5;

    // Create an instance of the Solution class
    Solution sol;

    // Calling the generate function to generate Pascal's Triangle
    vector<vector<int>> result = sol.generate(numRows);

    // Output the result
    cout << "Pascal's Triangle with " << numRows << " rows is:" << endl;
    for (const auto& row : result) {
        for (int num : row) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}
