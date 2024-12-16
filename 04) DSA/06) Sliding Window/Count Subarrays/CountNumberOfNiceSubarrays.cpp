#include <bits/stdc++.h>
using namespace std;
//link: https://takeuforward.org/plus/data-structures-and-algorithm/sliding-window-and-2-pointer/counting-subarrays-and-substrings-problems/count-number-of-nice-subarrays
class Solution {
public:
    /* Function to find the number of subarrays
    nice subarrays with k odd numbers*/
    int numberOfOddSubarrays(vector<int>& nums, int k) {
        
        /*Calculate the number of subarrays with 
        sum exactly equal to k by using the 
        difference between subarrays with sum less
        than or equal to k and those with sum
        less than or equal to k-1*/
        return helper(nums, k) - helper(nums, k - 1);
    }
    
private:
    /* Helper function to find the number of 
    subarrays with sum less than or equal to k*/
    int helper(vector<int>& nums, int k) {
        
        /* If goal is negative, there 
        can't be any valid subarray sum*/
        if (k < 0) return 0;
        
        //Pointers to maintain the current window
        int l = 0, r = 0; 
        
        /* Variable to track the current 
        sum of elements in the window*/
        int sum = 0;      
        
        // Variable to count the number of subarrays
        int count = 0;   
        
        /* Iterate through the array 
        using the right pointer `r`*/
        while (r < nums.size()) {
            sum = sum + nums[r] % 2; 
            
            /* Shrink the window from the left
            side if the sum exceeds k*/
            while (sum > k) {
                sum = sum -  nums[l] % 2;  
                
                // Move the left pointer `l` forward
                l++;            
            }
            
            /* Count all subarrays ending at
            `r` that satisfy the sum condition*/
            count += (r - l + 1);
            
            // Move the right pointer `r` forward 
            r++; 
        }
        
        // Return the total count of subarrays
        return count;
    }
};

int main() {
    vector<int> nums = {1, 1, 2, 1, 1};
    int k = 1;
    
    // Create an instance of Solution class
    Solution sol;
    
    int ans = sol.numberOfOddSubarrays(nums, k);

    // Print the result
    cout << "Number of nice substrings with \"" << k << "\" odd numbers is: " << ans << endl;

    return 0;
}