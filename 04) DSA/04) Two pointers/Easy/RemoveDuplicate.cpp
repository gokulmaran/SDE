#include <iostream>
#include <vector>

using namespace std;
//Link:https://www.geeksforgeeks.org/problems/remove-duplicate-elements-from-sorted-array/1
class Solution {
public:
    // Function to remove duplicates from a sorted array
    int remove_duplicate(vector<int> &arr) {
        int k = 0; // Pointer to the position of the next unique element
        int n = arr.size(); // Size of the array

        // Iterate through the array
        for (int i = 0; i < arr.size() - 1; i++) {
            if (arr[i] != arr[i + 1]) {
                arr[k++] = arr[i]; // Move unique elements to the front
            }
        }
        // Add the last element
        arr[k++] = arr[n - 1];

        return k; // New length of the array with unique elements
    }
};

int main() {
    Solution sol;

    // Test case 1
    vector<int> arr1 = {1, 1, 2, 2, 3, 4, 4, 5};

    // Test case 2
    vector<int> arr2 = {1, 1, 1, 1, 2, 3, 4, 4};

    // Remove duplicates and get the new length
    int newLength1 = sol.remove_duplicate(arr1);
    int newLength2 = sol.remove_duplicate(arr2);

    // Output the results
    cout << "Array after removing duplicates (test case 1): ";
    for (int i = 0; i < newLength1; i++) {
        cout << arr1[i] << " ";
    }
    cout << endl;

    cout << "Array after removing duplicates (test case 2): ";
    for (int i = 0; i < newLength2; i++) {
        cout << arr2[i] << " ";
    }
    cout << endl;

    return 0;
}
