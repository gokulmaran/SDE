#include <iostream>
#include <algorithm> // For sort function

using namespace std;
//Link: https://www.geeksforgeeks.org/problems/intersection-of-two-arrays2404/1
class Solution {
public:
    // Function to return the count of the number of elements in
    // the intersection of two arrays.
    int NumberofElementsInIntersection(int a[], int b[], int n, int m) {
        long long cnt = 0; // Count of intersecting elements
        int i = 0, j = 0;  // Pointers for array a and b respectively

        // Sort both arrays
        sort(a, a + n);
        sort(b, b + m);

        // Find the intersection of two arrays
        while (i < n && j < m) {
            if (a[i] == b[j]) {
                cnt++;
                i++;
                j++;
                // Skip duplicate elements in array a
                while (i < n && a[i] == a[i - 1]) {
                    i++;
                }
                // Skip duplicate elements in array b
                while (j < m && b[j] == b[j - 1]) {
                    j++;
                }
            } else if (a[i] < b[j]) {
                i++;
            } else {
                j++;
            }
        }

        return cnt; // Return the count of intersecting elements
    }
};

int main() {
    Solution sol;

    // Test cases
    int a1[] = {1, 2, 2, 1};
    int b1[] = {2, 2};
    int n1 = sizeof(a1) / sizeof(a1[0]);
    int m1 = sizeof(b1) / sizeof(b1[0]);

    int a2[] = {4, 9, 5};
    int b2[] = {9, 4, 9, 8, 4};
    int n2 = sizeof(a2) / sizeof(a2[0]);
    int m2 = sizeof(b2) / sizeof(b2[0]);

    // Find the number of elements in the intersection of the two arrays
    int result1 = sol.NumberofElementsInIntersection(a1, b1, n1, m1);
    int result2 = sol.NumberofElementsInIntersection(a2, b2, n2, m2);

    // Output the results
    cout << "Number of elements in intersection (test case 1): " << result1 << endl;
    cout << "Number of elements in intersection (test case 2): " << result2 << endl;

    return 0;
}
