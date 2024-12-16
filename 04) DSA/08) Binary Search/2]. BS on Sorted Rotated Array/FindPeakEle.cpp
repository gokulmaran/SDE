#include <iostream>
#include <vector>
using namespace std;
//Link: https://leetcode.com/problems/find-peak-element/description/
class Solution {
public:
    // Function to find a peak element in an array
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        
        // Handle special cases
        if (n == 1) return 0;               // Single element is always a peak
        if (nums[0] > nums[1]) return 0;   // First element is a peak
        if (nums[n-1] > nums[n-2]) return n-1; // Last element is a peak

        // Binary search to find the peak element
        int s = 1, e = nums.size() - 2;     // Start with the second element and end with the second-to-last element
        while (s <= e) {
            int mid = (s + e) / 2;

            // Check if mid is a peak
            if (nums[mid - 1] < nums[mid] && nums[mid] > nums[mid + 1]) {
                return mid;
            }
            // If the mid element is greater than the previous element, move right
            else if (nums[mid] > nums[mid - 1]) {
                s = mid + 1;
            }
            // Otherwise, move left
            else {
                e = mid - 1;
            }
        }
        return -1; // Should not reach here if the input array is valid
    }
};

int main() {
    Solution sol;

    // Example test cases
    vector<vector<int>> testCases = {
        {1, 2, 3, 1},           // Peak is 3 at index 2
        {1, 2, 1, 3, 5, 6, 4},  // Peaks are 2 at index 1 and 6 at index 5
        {1, 2, 3, 4, 5},        // Peak is 5 at index 4
        {5, 4, 3, 2, 1},        // Peak is 5 at index 0
        {1}                     // Peak is 1 at index 0 (only one element)
    };

    // Testing findPeakElement function
    for (const auto& nums : testCases) {
        int peakIndex = sol.findPeakElement(const_cast<vector<int>&>(nums));
        cout << "Peak element is at index " << peakIndex << " with value " << nums[peakIndex] << "." << endl;
    }

    return 0;
}
