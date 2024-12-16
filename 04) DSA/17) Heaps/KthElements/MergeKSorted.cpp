#include <iostream>
#include <vector>
#include <queue>
using namespace std;
//Link: https://www.geeksforgeeks.org/problems/merge-k-sorted-arrays/1
class Solution {
public:
    // Function to merge k sorted arrays
    vector<int> mergeKArrays(vector<vector<int>> arr, int k) {
        // Create a min-heap (priority queue with greater<int> comparator)
        priority_queue<int, vector<int>, greater<int>> pq;
        
        // Insert all elements of k sorted arrays into the min-heap
        for (int i = 0; i < k; ++i) {
            for (int j = 0; j < k; ++j) {
                pq.push(arr[i][j]);
            }
        }
        
        // Extract elements from the min-heap to get the merged result
        vector<int> ans;
        while (!pq.empty()) {
            ans.push_back(pq.top());
            pq.pop();
        }
        return ans;
    }
};

int main() {
    Solution solution;

    // Example 1
    vector<vector<int>> arr1 = {
        {1, 3, 5},
        {2, 4, 6},
        {0, 7, 8}
    };
    int k1 = arr1.size(); // Number of arrays
    vector<int> result1 = solution.mergeKArrays(arr1, k1);
    cout << "Merged array (Example 1): ";
    for (int num : result1) {
        cout << num << " ";
    }
    cout << endl;

    // Example 2
    vector<vector<int>> arr2 = {
        {10, 20, 30},
        {5, 15, 25},
        {1, 8, 12}
    };
    int k2 = arr2.size(); // Number of arrays
    vector<int> result2 = solution.mergeKArrays(arr2, k2);
    cout << "Merged array (Example 2): ";
    for (int num : result2) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
