#include <iostream>
using namespace std;
//Link: https://www.geeksforgeeks.org/problems/bubble-sort/1
class Solution {
public:
    // Function to sort the array using bubble sort algorithm.
    void bubbleSort(int arr[], int n) {
        // Bubble sort algorithm
        for(int i = n - 1; i >= 0; i--) {
            for(int j = 0; j < i; j++) {
                if(arr[j] > arr[j + 1]) {
                    swap(arr[j], arr[j + 1]);
                }
            }
        }
    }
};

int main() {
    Solution sol;

    // Example array
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Call the bubbleSort method
    sol.bubbleSort(arr, n);

    // Output the sorted array
    cout << "Sorted array: ";
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
