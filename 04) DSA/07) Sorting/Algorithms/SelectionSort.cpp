#include <iostream>
using namespace std;
//Link: https://www.geeksforgeeks.org/problems/selection-sort/1
class Solution {
public:
    // Function to perform selection sort on the array.
    void selectionSort(int arr[], int n) {
        // Selection sort algorithm
        for(int i = 0; i < n - 1; i++) {
            int mini = i;
            for(int j = i + 1; j < n; j++) {
                if(arr[j] < arr[mini]) {
                    mini = j;
                }
            }
            swap(arr[mini], arr[i]);
        }
    }
};

int main() {
    Solution sol;

    // Example array
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Call the selectionSort method
    sol.selectionSort(arr, n);

    // Output the sorted array
    cout << "Sorted array: ";
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
