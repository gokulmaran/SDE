#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;
//Link: https://leetcode.com/problems/task-scheduler/description/
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int ans = 0;
        unordered_map<char, int> mp;
        for (char task : tasks) mp[task]++;
        priority_queue<int> pq;
        for (auto it : mp) pq.push(it.second);
        while (!pq.empty()) {
            vector<int> doneTasks;
            int cycle = n + 1;
            while (cycle && !pq.empty()) {
                int res = pq.top();
                pq.pop();
                if (res > 1) {
                    doneTasks.push_back(res - 1);
                }
                ++ans;
                --cycle;
            }
            for (int i : doneTasks) {
                pq.push(i);
            }
            if (pq.empty()) break;
            ans += cycle;
        }
        return ans;
    }
};

int main() {
    Solution sol;

    // Example input
    vector<char> tasks = {'A', 'A', 'A', 'B', 'B', 'B'};
    int n = 2;

    // Calculate the least interval
    int result = sol.leastInterval(tasks, n);

    // Output the result
    cout << "Least interval required: " << result << endl;

    return 0;
}
