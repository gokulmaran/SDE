#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
//Link: https://leetcode.com/problems/median-of-two-sorted-arrays/description/
class Solution {
public:
    double findMedianSortedArrays(vector<int>& a, vector<int>& b) {
        int n1 = a.size();
        int n2 = b.size();

        // Ensure that the first array is smaller or equal in size to the second array
        if (n1 > n2)
            return findMedianSortedArrays(b, a);

        int median = (n1 + n2 + 1) / 2;
        int s = 0, e = n1;
        while (s <= e) {
            int mid1 = (s + e) / 2;
            int mid2 = median - mid1;

            // Edge cases for left and right boundaries
            int l1 = mid1 == 0 ? INT_MIN : a[mid1 - 1];
            int l2 = mid2 == 0 ? INT_MIN : b[mid2 - 1];
            int r1 = mid1 == n1 ? INT_MAX : a[mid1];
            int r2 = mid2 == n2 ? INT_MAX : b[mid2];

            // Check if the correct partition is found
            if (l1 <= r2 && l2 <= r1) {
                if ((n1 + n2) % 2 == 0) {
                    return (max(l1, l2) + min(r1, r2)) / 2.0;
                } else {
                    return max(l1, l2);
                }
            } else if (l1 > r2) {
                // Move left boundary
                e = mid1 - 1;
            } else {
                // Move right boundary
                s = mid1 + 1;
            }
        }
        return 0.0; // This line should not be reached if inputs are valid
    }
};

int main() {
    Solution sol;

    // Test Case 1: Basic test with arrays of different sizes
    vector<int> a1 = {1, 3};
    vector<int> b1 = {2};
    cout << "Median of sorted arrays is: " << sol.findMedianSortedArrays(a1, b1) << endl; // Output: 2.0

    // Test Case 2: Arrays with the same size and mixed elements
    vector<int> a2 = {1, 2};
    vector<int> b2 = {3, 4};
    cout << "Median of sorted arrays is: " << sol.findMedianSortedArrays(a2, b2) << endl; // Output: 2.5

    // Test Case 3: Arrays with identical elements
    vector<int> a3 = {0, 0};
    vector<int> b3 = {0, 0};
    cout << "Median of sorted arrays is: " << sol.findMedianSortedArrays(a3, b3) << endl; // Output: 0.0

    // Test Case 4: One empty array
    vector<int> a4 = {};
    vector<int> b4 = {1};
    cout << "Median of sorted arrays is: " << sol.findMedianSortedArrays(a4, b4) << endl; // Output: 1.0

    // Test Case 5: Arrays with sequential elements
    vector<int> a5 = {1, 2, 3, 4, 5};
    vector<int> b5 = {6, 7, 8, 9, 10};
    cout << "Median of sorted arrays is: " << sol.findMedianSortedArrays(a5, b5) << endl; // Output: 5.5

    return 0;
}
