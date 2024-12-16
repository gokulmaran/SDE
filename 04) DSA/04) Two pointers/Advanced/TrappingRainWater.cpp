#include <iostream>
#include <algorithm>

using namespace std;
//link: https://leetcode.com/problems/trapping-rain-water/description/
class Solution {
public:
    // Function to calculate the amount of water trapped between the bars
    int trap(int A[], int n) {
        int left = 0; // Left pointer
        int right = n - 1; // Right pointer
        int res = 0; // Result to store the total water trapped
        int maxleft = 0; // Maximum height to the left of the current bar
        int maxright = 0; // Maximum height to the right of the current bar

        while (left <= right) {
            if (A[left] <= A[right]) {
                // If the height at the left pointer is less than or equal to the height at the right pointer
                if (A[left] >= maxleft) {
                    // Update the maximum height to the left
                    maxleft = A[left];
                } else {
                    // Calculate water trapped at the current position
                    res += maxleft - A[left];
                }
                left++; // Move the left pointer to the right
            } else {
                // If the height at the right pointer is less than the height at the left pointer
                if (A[right] >= maxright) {
                    // Update the maximum height to the right
                    maxright = A[right];
                } else {
                    // Calculate water trapped at the current position
                    res += maxright - A[right];
                }
                right--; // Move the right pointer to the left
            }
        }
        return res; // Return the total amount of water trapped
    }
};

int main() {
    Solution sol;

    // Test case 1
    int A1[] = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    int n1 = sizeof(A1) / sizeof(A1[0]);

    // Test case 2
    int A2[] = {4, 2, 0, 3, 2, 5};
    int n2 = sizeof(A2) / sizeof(A2[0]);

    // Calculate the amount of water trapped for each test case
    int result1 = sol.trap(A1, n1);
    int result2 = sol.trap(A2, n2);

    // Output the results
    cout << "Test case 1: " << result1 << " units of water trapped" << endl;
    cout << "Test case 2: " << result2 << " units of water trapped" << endl;

    return 0;
}
