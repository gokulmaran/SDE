#include <bits/stdc++.h>
using namespace std;
//Link: https://takeuforward.org/plus/data-structures-and-algorithm/binary-search/fundamentals/lower-bound-
class Solution {
public:
    // Function to find the lower bound
    int lowerBound(vector<int>& nums, int x) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            /* Check the condition for 
               the current element */
            if (nums[i] >= x) {
                // If lower bound is found 
                return i;
            }
        }
        /* If lower bound of 
           target is not found */
        return n;
    }
};

int main() {
    vector<int> arr = {1, 2, 2, 3};
    int x = 2;
    
    // Create an instance of the Solution class
    Solution sol;
    
    // Function call to find the lower bound
    int ind = sol.lowerBound(arr, x);
    
    cout << "The lower bound is the index: " << ind << "\n";
    
    return 0;
}