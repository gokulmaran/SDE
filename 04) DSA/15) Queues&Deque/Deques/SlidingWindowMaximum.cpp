#include <iostream>
#include <vector>
#include <deque>
using namespace std;
//link: https://leetcode.com/problems/sliding-window-maximum/
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& arr, int k) {
        int i = 0, j = 0;
        vector<int> ans;
        int n = arr.size();
        deque<int> dq;

        while (i < n) {
            // Remove indices that are out of the current window
            if (!dq.empty() && dq.front() < i - k + 1) {
                dq.pop_front();
            }
            
            // Remove elements from the back of the deque that are smaller than the current element
            while (!dq.empty() && arr[dq.back()] < arr[i]) {
                dq.pop_back();
            }
            
            // Add the current element index to the deque
            dq.push_back(i++);
            
            // Once we have processed at least k elements, add the maximum of the current window to the result
            if (i >= k) {
                ans.push_back(arr[dq.front()]);
            }
        }
        
        return ans;
    }
};

int main() {
    Solution sol;

    // Example input
    vector<int> arr = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;

    // Get the maximum values of sliding windows
    vector<int> result = sol.maxSlidingWindow(arr, k);

    // Output the results
    cout << "Maximum values in each sliding window of size " << k << ": ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
