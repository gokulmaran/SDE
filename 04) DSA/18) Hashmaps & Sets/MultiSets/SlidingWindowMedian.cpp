#include <iostream>
#include <vector>
#include <set>
#include <iterator>

using namespace std;
//Link: https://leetcode.com/problems/sliding-window-median/
class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        
        multiset<int> window(nums.begin(), nums.begin() + k);
        
        auto mid = next(window.begin(), k / 2);
        
        vector<double> medians;
        
        for (int i = k; ; i++) {

            // Push the current median.
            medians.push_back((double(*mid) + *prev(mid, 1 - k % 2)) / 2);

            // If all done, return.
            if (i == nums.size())
                return medians;
                
            // Insert nums[i].
            window.insert(nums[i]);
            if (nums[i] < *mid)
                mid--;

            // Erase nums[i-k].
            if (nums[i - k] <= *mid)
                mid++;
            window.erase(window.lower_bound(nums[i - k]));
        }
    }
};

int main() {
    Solution sol;

    // Example input
    vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;

    // Call the medianSlidingWindow method
    vector<double> medians = sol.medianSlidingWindow(nums, k);
    
    // Output the result
    cout << "Medians of sliding window: ";
    for (double median : medians) {
        cout << median << " ";
    }
    cout << endl;

    return 0;
}
