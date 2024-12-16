#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>

using namespace std;
//Link: https://leetcode.com/problems/minimum-cost-to-hire-k-workers/
class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        int n = quality.size();
        double sum = 0, result = INT_MAX;
        vector<pair<double, int>> details;
        for (int i = 0; i < n; i++) {
            details.push_back({wage[i] / (double)quality[i], quality[i]});
        }
        sort(details.begin(), details.end());
        priority_queue<int> pq; 
        for (int i = 0; i < n; i++) {
            pq.push(details[i].second);
            sum += details[i].second;
            if (pq.size() > k) {
                sum -= pq.top();
                pq.pop();
            }
            if (pq.size() == k) {
                result = min(result, sum * details[i].first);
            }
        }
        return result;
    }
};

int main() {
    Solution sol;

    // Example inputs
    vector<int> quality = {10, 20, 5};
    vector<int> wage = {70, 50, 30};
    int k = 2;

    // Calculate the minimum cost
    double result = sol.mincostToHireWorkers(quality, wage, k);

    // Output the result
    cout << "Minimum cost to hire " << k << " workers: " << result << endl;

    return 0;
}
