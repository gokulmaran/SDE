#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
//Link: https://leetcode.com/problems/merge-intervals/
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.size() <= 1) return intervals;
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> output;
        output.push_back(intervals[0]);

        for (int i = 1; i < intervals.size(); i++) {
            if (output.back()[1] >= intervals[i][0]) {
                output.back()[1] = max(output.back()[1], intervals[i][1]);
            } else {
                output.push_back(intervals[i]);
            }
        }
        return output;
    }
};

int main() {
    Solution solution;

    // Define the intervals
    vector<vector<int>> intervals = {
        {1, 3},
        {2, 6},
        {8, 10},
        {15, 18}
    };

    // Get the merged intervals
    vector<vector<int>> mergedIntervals = solution.merge(intervals);

    // Output the result
    cout << "Merged intervals are: " << endl;
    for (const auto& interval : mergedIntervals) {
        cout << "[" << interval[0] << ", " << interval[1] << "] ";
    }
    cout << endl;

    return 0;
}
