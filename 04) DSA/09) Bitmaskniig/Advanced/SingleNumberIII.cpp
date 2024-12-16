#include <bits/stdc++.h>
using namespace std;
//Link: https://takeuforward.org/plus/data-structures-and-algorithm/bit-manipulation/problems/single-number---iii
class Solution {
public:
    /* Function to get the single 
    numbers in the given array */
    vector<int> singleNumber(vector<int>& nums){
        // Variable to store size of array
        int n = nums.size();
        
        // Variable to store XOR of all elements
        long XOR;
        
        // Traverse the array
        for(int i=0; i < n; i++) {
            
            // Update the XOR
            XOR = XOR ^ nums[i];
        }
        
        /* Variable to get the rightmost 
        set bit in overall XOR */
        int rightmost = (XOR & (XOR - 1)) ^ XOR;
        
        /* Variables to stores XOR of
        elements in bucket 1 and 2 */
        int XOR1 = 0, XOR2 = 0;
        
        // Traverse the array
        for(int i=0; i < n; i++) {
            
            /* Divide the numbers among bucket 1
             and 2 based on rightmost set bit */
            if(nums[i] & rightmost) {
                XOR1 = XOR1 ^ nums[i];
            }
            else {
                XOR2 = XOR2 ^ nums[i];
            }
        }
        
        // Return the result in sorted order
        if(XOR1 < XOR2) return {XOR1, XOR2};
        return {XOR2, XOR1};
    }
};

int main() {
    vector<int> nums = {1, 2, 1, 3, 5, 2};
    
    /* Creating an instance of 
    Solution class */
    Solution sol; 
    
    /* Function call to get the single 
    numbers in the given array */
    vector<int> ans = sol.singleNumber(nums);
    
    cout << "The single numbers in given array are: " << ans[0] << " and " << ans[1];
    
    return 0;
}
