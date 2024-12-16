#include <iostream>
#include <vector>
#include <queue>
using namespace std;

//Link: https://www.geeksforgeeks.org/problems/kth-smallest-element5635/1
class Solution {
public:
    // arr : given array
    // l : starting index of the array i.e 0
    // r : ending index of the array i.e size-1
    // k : find kth smallest element and return using this function
    int kthSmallest(int arr[], int l, int r, int k) {
        // Create a max-heap (priority queue with default greater<int> comparator)
        priority_queue<int> pq;
        for (int i = l; i <= r; ++i) {
            pq.push(arr[i]);
            if (pq.size() > k) {
                pq.pop(); // Remove the largest element to maintain heap size k
            }
        }
        // The root of the max-heap is the kth smallest element
        return pq.top();
    }
};

int main() {
    Solution solution;

    int arr1[] = {7, 10, 4, 3, 20, 15};
    int l1 = 0;
    int r1 = 5;
    int k1 = 3; // Find the 3rd smallest element
    cout << "The " << k1 << "rd smallest element is: " << solution.kthSmallest(arr1, l1, r1, k1) << endl;

    int arr2[] = {1, 5, 12, 2, 11, 5};
    int l2 = 0;
    int r2 = 5;
    int k2 = 4; // Find the 4th smallest element
    cout << "The " << k2 << "th smallest element is: " << solution.kthSmallest(arr2, l2, r2, k2) << endl;

    return 0;
}
