#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
//Link:https://leetcode.com/problems/non-overlapping-intervals/description/
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.empty()) return 0;

        sort(intervals.begin(), intervals.end());
        int cnt = 0;
        int currEnd = intervals[0][1];

        for (int i = 1; i < intervals.size(); i++) {
            if (currEnd > intervals[i][0]) {
                // Overlapping intervals
                currEnd = min(currEnd, intervals[i][1]);
                cnt++;
            } else {
                // Non-overlapping interval, update current end
                currEnd = intervals[i][1];
            }
        }

        return cnt;
    }
};

int main() {
    Solution solution;

    // Define the intervals
    vector<vector<int>> intervals = {
        {1, 3},
        {2, 4},
        {3, 5},
        {5, 7},
        {6, 8}
    };

    // Get the number of intervals to remove
    int numToRemove = solution.eraseOverlapIntervals(intervals);

    // Output the result
    cout << "Number of intervals to remove: " << numToRemove << endl;

    return 0;
}
