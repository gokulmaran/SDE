#include <iostream>
#include <vector>

using namespace std;
//Link: https://leetcode.com/problems/flood-fill/description/
// Solution class definition
class Solution {
public:
    void dfs(vector<vector<int>>& image, int i, int j, int val, int newColor) {
        if (i < 0 || i >= image.size() || j < 0 || j >= image[0].size() || image[i][j] == newColor || image[i][j] != val) {
            return;
        }
        image[i][j] = newColor;

        // Explore all 4 directions
        dfs(image, i - 1, j, val, newColor);
        dfs(image, i + 1, j, val, newColor);
        dfs(image, i, j - 1, val, newColor);
        dfs(image, i, j + 1, val, newColor);
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int val = image[sr][sc];
        dfs(image, sr, sc, val, color);
        return image;
    }
};

// Main function
int main() {
    Solution sol;
    
    // Example test case
    vector<vector<int>> image = {
        {1, 1, 1},
        {1, 1, 0},
        {1, 0, 1}
    };
    int sr = 1; // Starting row
    int sc = 1; // Starting column
    int newColor = 2; // New color to fill

    vector<vector<int>> result = sol.floodFill(image, sr, sc, newColor);

    cout << "Updated image:" << endl;
    for (const auto& row : result) {
        for (int pixel : row) {
            cout << pixel << " ";
        }
        cout << endl;
    }

    return 0;
}
