#include <iostream>
#include <vector>
#include <queue>
using namespace std;
//Link: https://leetcode.com/problems/kth-largest-element-in-an-array/
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int i = 0; i < nums.size(); ++i) {
            pq.push(nums[i]);
            if (pq.size() > k) {
                pq.pop();
            }
        }
        return pq.top(); // Return the kth largest element
    }
};

int main() {
    Solution solution;

    vector<int> nums1 = {3, 2, 1, 5, 6, 4}; // Example array
    int k1 = 2; // Find the 2nd largest element
    cout << "The " << k1 << "th largest element is: " << solution.findKthLargest(nums1, k1) << endl;

    vector<int> nums2 = {1, 2, 3, 4, 5}; // Another example array
    int k2 = 4; // Find the 4th largest element
    cout << "The " << k2 << "th largest element is: " << solution.findKthLargest(nums2, k2) << endl;

    return 0;
}
