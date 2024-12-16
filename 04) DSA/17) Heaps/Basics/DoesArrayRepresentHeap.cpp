#include <iostream>
using namespace std;
//link: https://www.geeksforgeeks.org/problems/does-array-represent-heap4345/1
class Solution {
public:
    bool isMaxHeap(int arr[], int n) {
        for (int i = n / 2 - 1; i >= 0; i--) {
            int left = 2 * i + 1;
            int right = 2 * i + 2;
            
            // Check if left child exists and is greater than parent
            if (left < n && arr[i] < arr[left]) {
                return false;
            }
            
            // Check if right child exists and is greater than parent
            if (right < n && arr[i] < arr[right]) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    Solution solution;

    int maxHeap[] = {10, 5, 6, 2, 3}; // Example max-heap
    int sizeMaxHeap = sizeof(maxHeap) / sizeof(maxHeap[0]);

    int nonMaxHeap[] = {10, 5, 6, 7, 3}; // Example non-max-heap
    int sizeNonMaxHeap = sizeof(nonMaxHeap) / sizeof(nonMaxHeap[0]);

    bool resultMaxHeap = solution.isMaxHeap(maxHeap, sizeMaxHeap);
    bool resultNonMaxHeap = solution.isMaxHeap(nonMaxHeap, sizeNonMaxHeap);

    cout << "Is the first array a max-heap? " << (resultMaxHeap ? "Yes" : "No") << endl;
    cout << "Is the second array a max-heap? " << (resultNonMaxHeap ? "Yes" : "No") << endl;

    return 0;
}
