#include <bits/stdc++.h>
using namespace std;
//Link: https://takeuforward.org/plus/data-structures-and-algorithm/greedy-algorithms/scheduling-and-interval-problems/shortest-job-first
class Solution {
public:
    /*Function to calculate total waiting 
    time using Shortest Job First algorithm*/
    long long solve(vector<int>& bt) {
        // Sort jobs in ascending order
        sort(bt.begin(), bt.end());

        // Initialize total waiting time
        long long waitTime = 0;
        // Initialize total time taken
        long long totalTime = 0;
        // Get number of jobs
        int n = bt.size();

        // Iterate to calculate waiting time
        for (int i = 0; i < n; ++i) {
            waitTime += totalTime;
            totalTime += bt[i];
        }

        // Return average waiting time
        return waitTime/n;
    }
};

int main() {
    vector<int> jobs = {1, 2, 3, 4};

    cout << "Array Representing Job Durations: ";
    for (int i = 0; i < jobs.size(); i++) {
        cout << jobs[i] << " ";
    }
    cout << endl;

    Solution solution;
    long long ans = solution.solve(jobs);
    cout << "Total waiting time: " << ans << endl;

    return 0;
}