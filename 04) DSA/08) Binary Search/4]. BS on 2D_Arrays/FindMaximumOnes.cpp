#include <bits/stdc++.h>
using namespace std;
//Link: https://takeuforward.org/plus/data-structures-and-algorithm/binary-search/2d-arrays/find-row-with-maximum-1's
class Solution {
private:
    //Helper function to find the lower bound of 1.
    int lowerBound(vector<int> arr, int n, int x) {
    int low = 0, high = n - 1;
    int ans = n;

    while (low <= high) {
        int mid = (low + high) / 2;
        
        /* If element at mid is greater than or equal 
        to x then it counld be a possible answer.*/
        if (arr[mid] >= x) {
            ans = mid;
            
            //Look for smaller index on the left
            high = mid - 1;
        }
        else {
            low = mid + 1; 
        }
    }
    //Return the answer
    return ans;
}
public:
    /* Function to find the row 
    with the maximum number of 1's*/
    int rowWithMax1s(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        
        /* Variable to store the 
        maximum count of 1's found*/
        int cnt_max = 0; 
        
        /* Variable to store the index
        of the row with max 1's*/
        int index = -1;  

        //Traverse each row of the matrix
        for (int i = 0; i < n; i++) {
            // Get the number of 1's
            int cnt_ones = m - lowerBound(mat[i], m, 1);
            
            /*If the current count is greater than 
            maximum, store the index of current row
            and update the maximum count.*/
            if (cnt_ones > cnt_max) {
                cnt_max = cnt_ones;
                index = i;
            }
        }

        /* Return the index of the row 
        with the maximum number of 1's*/
        return index;
    }
};

int main() {
    vector<vector<int>> matrix = {{1, 1, 1}, {0, 0, 1}, {0, 0, 0}};
    
    // Create an instance of the Solution class
    Solution sol; 
    
    // Print the answer
    cout << "The row with maximum number of 1's is: " <<
            sol.rowWithMax1s(matrix) << '\n';

    return 0;
}
