#include <iostream>
#include <climits>

using namespace std;
//Link: https://www.geeksforgeeks.org/problems/k-th-element-of-two-sorted-array1317/1
class Solution {
public:
    int kthElement(int nums1[], int nums2[], int n1, int n2, int k) {
        // Ensure nums1 is the smaller array
        if (n1 > n2) return kthElement(nums2, nums1, n2, n1, k);
        
        // Total elements in the combined array
        int left = k; 
        int low = max(0, k - n2), high = min(k, n1); 
        
        while (low <= high) {
            int mid1 = (low + high) >> 1; 
            int mid2 = left - mid1;  
            
            // Left and right elements for comparison
            int l1 = INT_MIN, l2 = INT_MIN; 
            int r1 = INT_MAX, r2 = INT_MAX;  
            
            if (mid1 < n1) r1 = nums1[mid1]; 
            if (mid2 < n2) r2 = nums2[mid2];  
            if (mid1 - 1 >= 0) l1 = nums1[mid1 - 1]; 
            if (mid2 - 1 >= 0) l2 = nums2[mid2 - 1]; 
            
            if (l1 <= r2 && l2 <= r1) {
                // If valid partition, return the maximum of left side
                return max(l1, l2); 
            } else if (l1 > r2) {
                // Adjust search range
                high = mid1 - 1; 
            } else {
                low = mid1 + 1;    
            }
        }
        return 0;    
    }
};

int main() {
    Solution sol;

    // Test Case 1: Basic test with small arrays
    int nums1_1[] = {1, 3, 5};
    int nums2_1[] = {2, 4, 6};
    int k1 = 4;
    // Expected output: 4
    cout << "The " << k1 << "-th smallest element is: " << sol.kthElement(nums1_1, nums2_1, 3, 3, k1) << endl;

    // Test Case 2: Arrays of different sizes
    int nums1_2[] = {1, 2};
    int nums2_2[] = {3, 4, 5};
    int k2 = 4;
    // Expected output: 4
    cout << "The " << k2 << "-th smallest element is: " << sol.kthElement(nums1_2, nums2_2, 2, 3, k2) << endl;

    // Test Case 3: Arrays with overlapping ranges
    int nums1_3[] = {1, 5, 7, 9};
    int nums2_3[] = {2, 3, 6, 8, 10};
    int k3 = 5;
    // Expected output: 6
    cout << "The " << k3 << "-th smallest element is: " << sol.kthElement(nums1_3, nums2_3, 4, 5, k3) << endl;

    // Test Case 4: One empty array
    int nums1_4[] = {};
    int nums2_4[] = {1, 2, 3, 4, 5};
    int k4 = 3;
    // Expected output: 3
    cout << "The " << k4 << "-th smallest element is: " << sol.kthElement(nums1_4, nums2_4, 0, 5, k4) << endl;

    // Test Case 5: All elements in one array are smaller
    int nums1_5[] = {1, 2, 3};
    int nums2_5[] = {4, 5, 6};
    int k5 = 6;
    // Expected output: 6
    cout << "The " << k5 << "-th smallest element is: " << sol.kthElement(nums1_5, nums2_5, 3, 3, k5) << endl;

    return 0;
}
