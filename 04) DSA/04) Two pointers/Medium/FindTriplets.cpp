#include <iostream>
#include <algorithm>

using namespace std;
//Link:https://www.geeksforgeeks.org/problems/find-triplets-with-zero-sum/1
class Solution {
public:
    // Function to find if there are triplets in the array that sum to zero
    bool findTriplets(int arr[], int n) {
        if (n < 3) {
            return false; // Not enough elements to form a triplet
        }
        sort(arr, arr + n); // Sort the array
        for (int i = 0; i < n - 2; i++) {
            int j = i + 1;
            int k = n - 1;
            while (j < k) {
                int sum = arr[i] + arr[j] + arr[k];
                if (sum == 0) {
                    return true; // Triplet found
                } else if (sum < 0) {
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
    int arr1[] = {0, -1, 2, -3, 1};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);

    // Test case 2
    int arr2[] = {1, 2, -2, -1};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);

    // Check if there are triplets in the array that sum to zero
    bool result1 = sol.findTriplets(arr1, n1);
    bool result2 = sol.findTriplets(arr2, n2);

    // Output the results
    cout << "Test case 1: " << (result1 ? "Yes" : "No") << endl;
    cout << "Test case 2: " << (result2 ? "Yes" : "No") << endl;

    return 0;
}
