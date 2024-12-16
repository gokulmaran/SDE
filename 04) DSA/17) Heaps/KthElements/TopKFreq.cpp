#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;
//Link: https://leetcode.com/problems/top-k-frequent-elements/
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // Create a frequency map
        unordered_map<int, int> m;
        for (int num : nums) {
            m[num]++;
        }
        
        // Create a max-heap (priority queue) based on frequency
        priority_queue<pair<int, int>> pq;
        for (const auto& entry : m) {
            pq.push({entry.second, entry.first});
        }
        
        // Extract the top k frequent elements
        vector<int> ans;
        while (k-- && !pq.empty()) {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        
        return ans;
    }
};

int main() {
    Solution solution;

    // Example 1
    vector<int> nums1 = {1, 1, 1, 2, 2, 3};
    int k1 = 2;
    vector<int> result1 = solution.topKFrequent(nums1, k1);
    cout << "Top " << k1 << " frequent elements (Example 1): ";
    for (int num : result1) {
        cout << num << " ";
    }
    cout << endl;

    // Example 2
    vector<int> nums2 = {1, 2, 3, 4, 4, 4, 5, 5, 5, 5};
    int k2 = 3;
    vector<int> result2 = solution.topKFrequent(nums2, k2);
    cout << "Top " << k2 << " frequent elements (Example 2): ";
    for (int num : result2) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
