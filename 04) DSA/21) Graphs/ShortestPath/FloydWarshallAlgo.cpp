#include <bits/stdc++.h>
using namespace std;

//Link:https://www.geeksforgeeks.org/problems/implementing-floyd-warshall2042/1
void shortest_distance(vector<vector<int>>& matrix) {
    int n = matrix.size();
    
    // Replace -1 with a large value (infinity) to indicate no path
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(matrix[i][j] == -1) {
                matrix[i][j] = 1e9; // Using 1e9 as a large number to represent infinity
            }
        }
    }
    
    // Floyd-Warshall algorithm
    for(int via = 0; via < n; via++) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                // Update the shortest distance from i to j via 'via'
                matrix[i][j] = min(matrix[i][j], matrix[i][via] + matrix[via][j]);
            }
        }
    }
    
    // Convert the distance back to -1 if it is still set as infinity
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(matrix[i][j] == 1e9) {
                matrix[i][j] = -1; // No path exists
            }
        }
    }
}

// Main function to test the shortest_distance function
int main() {
    int n; // Number of nodes
    cin >> n; // Read the number of nodes

    vector<vector<int>> matrix(n, vector<int>(n)); // Initialize matrix of size n x n

    // Read the matrix values
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }

    // Compute the shortest distances
    shortest_distance(matrix);

    // Output the result
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
