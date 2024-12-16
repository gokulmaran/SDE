#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//Link: https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/
class Solution {
public:
    // Comparator function to sort intervals by their end points
    static bool cmp(const vector<int>& a, const vector<int>& b) {
        return a[1] < b[1];
    }
    
    // Function to find the minimum number of arrows needed to burst all balloons
    int findMinArrowShots(vector<vector<int>>& points) {
        // Sort the points by their end values
        sort(points.begin(), points.end(), cmp);
        
        int cnt = 1; // At least one arrow is needed
        int prev = 0; // Index of the last balloon that has been burst

        for (int i = 1; i < points.size(); i++) {
            // If the start of the current balloon is greater than the end of the last balloon that was burst
            if (points[i][0] > points[prev][1]) {
                cnt++; // Increase the count of arrows needed
                prev = i; // Update the index of the last balloon that was burst
            }
        }
        return cnt;
    }
};

int main() {
    Solution sol;

    // Example input: balloons represented by their start and end points
    vector<vector<int>> points = {{10, 16}, {2, 8}, {1, 6}, {7, 12}};

    // Call the findMinArrowShots method
    int result = sol.findMinArrowShots(points);

    // Output the result
    cout << "Minimum number of arrows required: " << result << endl;

    return 0;
}
