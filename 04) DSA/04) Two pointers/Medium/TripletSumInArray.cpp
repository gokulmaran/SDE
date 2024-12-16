#include <iostream>
#include <algorithm>

using namespace std;
//link:https://www.geeksforgeeks.org/problems/triplet-sum-in-array-1587115621/1
class Solution {
public:
    // Function to find if there exists a triplet in the array that sums to x
    bool find3Numbers(int arr[], int n, int x) {
        sort(arr, arr + n); // Sort the array
        for (int i = 0; i < n - 2; i++) {
            int j = i + 1;
            int k = n - 1;
            while (j < k) {
                int sum = arr[i] + arr[j] + arr[k];
                if (sum == x) {
                    return true; // Triplet found
                } else if (sum < x) {
                    j++; // Move left pointer to the right
                } else {
                    k--; // Move right pointer to the left
                }
            }
        }
        return false; // No triplet found
    }
};

int main() {
    Solution sol;

    // Test case 1
    int arr1[] = {12, 3, 4, 1, 6, 9};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    int x1 = 24;

    // Test case 2
    int arr2[] = {1, 2, 3, 4, 5, 6};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    int x2 = 10;

    // Check if there exists a triplet in the array that sums to x
    bool result1 = sol.find3Numbers(arr1, n1, x1);
    bool result2 = sol.find3Numbers(arr2, n2, x2);

    // Output the results
    cout << "Test case 1: " << (result1 ? "Yes" : "No") << endl;
    cout << "Test case 2: " << (result2 ? "Yes" : "No") << endl;

    return 0;
}
