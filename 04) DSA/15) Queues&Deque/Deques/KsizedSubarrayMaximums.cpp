#include <iostream>
#include <vector>
#include <deque>
using namespace std;
//Link: https://www.geeksforgeeks.org/problems/maximum-of-all-subarrays-of-size-k3101/1
class Solution {
public:
    // Function to find maximum of each subarray of size k.
    vector<int> max_of_subarrays(int *arr, int n, int k) {
        deque<int> dq;
        vector<int> result;
        
        for(int i = 0; i < n; i++) {
            // Remove elements out of the current window
            if(!dq.empty() && dq.front() == i - k) {
                dq.pop_front();
            }
            // Remove elements smaller than the currently being added element
            while(!dq.empty() && arr[dq.back()] <= arr[i]) {
                dq.pop_back();
            }
            dq.push_back(i);
            
            // The first element in the deque is the largest element of
            // the previous window, so add it to the result
            if(i >= k - 1) {
                result.push_back(arr[dq.front()]);
            }
        }
        return result;
    }
};

int main() {
    // Example input
    int arr[] = {1, 3, -1, -3, 5, 3, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3;

    // Create a Solution object
    Solution sol;
    
    // Get the maximum of each subarray of size k
    vector<int> result = sol.max_of_subarrays(arr, n, k);

    // Output the results
    cout << "Maximum of each subarray of size " << k << ": ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
