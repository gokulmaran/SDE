#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
//link: https://www.geeksforgeeks.org/problems/key-pair5616/1
class Solution {
public:
    // Function to check if the array has 2 elements whose sum is equal to the given value
    bool hasArrayTwoCandidates(vector<int>& arr, int x) {
        sort(arr.begin(), arr.end()); // Sort the array
        int i = 0, j = arr.size() - 1;
        while (i < j) {
            int sum = arr[i] + arr[j];
            if (sum == x) {
                return true; // Pair found
            } else if (sum < x) {
                i++; // Move left pointer to the right
            } else {
                j--; // Move right pointer to the left
            }
        }
        return false; // No pair found
    }
};

int main() {
    Solution sol;

    // Test case 1
    vector<int> arr1 = {10, 15, 3, 7};
    int x1 = 17;

    // Test case 2
    vector<int> arr2 = {1, 2, 3, 4, 5};
    int x2 = 10;

    // Check if there are two elements in the array whose sum is equal to the given value
    bool result1 = sol.hasArrayTwoCandidates(arr1, x1);
    bool result2 = sol.hasArrayTwoCandidates(arr2, x2);

    // Output the results
    cout << "Test case 1: " << (result1 ? "Yes" : "No") << endl;
    cout << "Test case 2: " << (result2 ? "Yes" : "No") << endl;

    return 0;
}
