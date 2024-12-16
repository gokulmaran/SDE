#include <iostream>
#include <vector>
#include <stack>

using namespace std;
//Link: https://leetcode.com/problems/daily-temperatures/
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans(n, 0);
        stack<int> s;

        for (int i = n - 1; i >= 0; i--) {
            while (!s.empty() && arr[s.top()] <= arr[i]) {
                s.pop();
            }
            if (!s.empty()) {
                ans[i] = s.top() - i;
            }
            s.push(i);
        }

        return ans;
    }
};

int main() {
    Solution sol;

    // Test case 1
    vector<int> temperatures1 = {73, 74, 75, 71, 69, 72, 76, 73};
    vector<int> result1 = sol.dailyTemperatures(temperatures1);
    cout << "Result for temperatures1: ";
    for (int days : result1) {
        cout << days << " ";
    }
    cout << endl; // Expected Output: 1 1 4 2 1 1 0 0

    // Test case 2
    vector<int> temperatures2 = {30, 40, 50, 60};
    vector<int> result2 = sol.dailyTemperatures(temperatures2);
    cout << "Result for temperatures2: ";
    for (int days : result2) {
        cout << days << " ";
    }
    cout << endl; // Expected Output: 1 1 1 0

    // Test case 3
    vector<int> temperatures3 = {30, 60, 90};
    vector<int> result3 = sol.dailyTemperatures(temperatures3);
    cout << "Result for temperatures3: ";
    for (int days : result3) {
        cout << days << " ";
    }
    cout << endl; // Expected Output: 1 1 0

    return 0;
}
