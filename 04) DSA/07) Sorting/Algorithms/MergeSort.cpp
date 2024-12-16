#include <iostream>
using namespace std;
//Link: https://www.geeksforgeeks.org/problems/merge-sort/1
class Solution {
public:
    // Function to merge two halves of the array
    void merge(int arr[], int l, int mid, int h) {
        int left = l;
        int right = mid + 1;
        int k = 0;
        int v[h - l + 1];
        
        // Merge the two halves into a temporary array
        while (left <= mid && right <= h) {
            if (arr[left] <= arr[right]) {
                v[k] = arr[left];
                left++;
            } else {
                v[k] = arr[right];
                right++;
            }
            k++;
        }
        
        // Copy remaining elements from the left half, if any
        while (left <= mid) {
            v[k] = arr[left];
            left++;
            k++;
        }
        
        // Copy remaining elements from the right half, if any
        while (right <= h) {
            v[k] = arr[right];
            right++;
            k++;
        }
        
        // Copy sorted elements back to the original array
        for (int i = l; i <= h; i++) {
            arr[i] = v[i - l];
        }
    }
    
    // Function to perform merge sort
    void mergeSort(int arr[], int l, int h) {
        if (l >= h) return;
        
        int mid = (l + h) / 2;
        mergeSort(arr, l, mid);
        mergeSort(arr, mid + 1, h);
        merge(arr, l, mid, h);
    }
};

int main() {
    Solution sol;

    // Example array
    int arr[] = {38, 27, 43, 3, 9, 82, 10};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Call the mergeSort method
    sol.mergeSort(arr, 0, n - 1);

    // Output the sorted array
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
