#include <iostream>
#include <vector>
using namespace std;

// Function to generate Pascal's Triangle up to numRows
vector<vector<int>> generate(int numRows) {
    if (numRows == 0) {
        return {};
    }
    
    // Recursively generate the triangle for numRows - 1
    vector<vector<int>> ans = generate(numRows - 1);
    vector<int> res(numRows, 1);
    
    // Update the current row based on the last row in ans
    for (int i = 1; i < numRows - 1; i++) {
        res[i] = ans.back()[i - 1] + ans.back()[i];
    }
    
    // Add the current row to the result
    ans.push_back(res);
    return ans;
}

int main() {
    int numRows;
    cout << "Enter the number of rows for Pascal's Triangle: ";
    cin >> numRows;

    // Call the generate function to get Pascal's Triangle
    vector<vector<int>> result = generate(numRows);

    // Print Pascal's Triangle
    cout << "Pascal's Triangle with " << numRows << " rows:" << endl;
    for (const auto& row : result) {
        for (int num : row) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}
