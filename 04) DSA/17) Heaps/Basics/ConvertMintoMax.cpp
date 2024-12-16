#include <iostream>
#include <vector>
using namespace std;
//link: https://www.geeksforgeeks.org/problems/convert-min-heap-to-max-heap-1666385109/1
class Solution {
public:
    void heapify(vector<int>& arr, int i, int n) {
        int left_child = 2 * i + 1;
        int right_child = 2 * i + 2;
        int largest = i;
        
        if (left_child < n && arr[left_child] > arr[largest]) {
            largest = left_child;
        }
        
        if (right_child < n && arr[right_child] > arr[largest]) {
            largest = right_child;
        }
        
        if (largest != i) {
            swap(arr[largest], arr[i]);
            heapify(arr, largest, n);
        }
    }

    void convertMinToMaxHeap(vector<int>& arr, int N) {
        // Convert the min-heap to max-heap
        for (int i = N / 2 - 1; i >= 0; i--) {
            heapify(arr, i, N);
        }
    }
};

int main() {
    Solution solution;
    vector<int> minHeap = {1, 3, 5, 7, 9, 2, 4, 6, 8, 0}; // Example min-heap
    int N = minHeap.size();

    cout << "Min-Heap before conversion: ";
    for (int num : minHeap) {
        cout << num << " ";
    }
    cout << endl;

    solution.convertMinToMaxHeap(minHeap, N);

    cout << "Max-Heap after conversion: ";
    for (int num : minHeap) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
