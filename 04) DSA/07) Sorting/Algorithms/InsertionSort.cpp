#include <iostream>
using namespace std;
//Link: https://www.geeksforgeeks.org/problems/insertion-sort/1
class Solution {
public:
    // Function to perform insertion sort on the array.
    void insertionSort(int a[], int n) {
        // Insertion sort algorithm
        for (int i = 1; i < n; i++) {
            int key = a[i];
            int j = i - 1;
            
            // Move elements of a[0..i-1] that are greater than key to one position ahead of their current position
            while (j >= 0 && a[j] > key) {
                a[j + 1] = a[j];
                j--;
            }
            a[j + 1] = key;
        }
    }
};

int main() {
    Solution sol;

    // Example array
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Call the insertionSort method
    sol.insertionSort(arr, n);

    // Output the sorted array
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
