#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
//link: https://www.geeksforgeeks.org/problems/n-meetings-in-one-room-1587115620/1
class Solution
{
public:
    // Function to find the maximum number of meetings that can
    // be performed in a meeting room.
    int maxMeetings(int start[], int end[], int n)
    {
        // Create a vector of pairs (end time, start time)
        vector<pair<int, int>> v;
        for (int i = 0; i < n; i++)
        {
            v.push_back({end[i], start[i]});
        }

        // Sort meetings based on end times
        sort(v.begin(), v.end());

        int cnt = 0;
        int e = -1; // End time of the last selected meeting

        for (int i = 0; i < n; i++)
        {
            // If the start time of the current meeting is greater than the end time of the last meeting
            if (e < v[i].second)
            {
                cnt++; // Include this meeting
                e = v[i].first; // Update the end time to the end time of the current meeting
            }
        }
        return cnt;
    }
};

int main()
{
    Solution solution;

    // Define the start and end times of meetings
    int start[] = {1, 2, 3, 3, 4};
    int end[] = {2, 3, 4, 5, 6};
    int n = sizeof(start) / sizeof(start[0]);

    // Get the maximum number of meetings that can be performed
    int maxMeetingsCount = solution.maxMeetings(start, end, n);

    // Output the result
    cout << "Maximum number of meetings that can be performed: " << maxMeetingsCount << endl;

    return 0;
}
