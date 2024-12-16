#include <iostream>
#include <vector>
#include <queue>

using namespace std;
//Link: https://leetcode.com/problems/course-schedule/
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& arr) {
        vector<vector<int>> graph(numCourses);
        vector<int> degree(numCourses, 0);
        queue<int> zeroDegree;
        
        // Building the graph and computing indegrees
        for (int i = 0; i < arr.size(); i++) {
            graph[arr[i][1]].push_back(arr[i][0]);
            degree[arr[i][0]]++;
        }

        // Finding all courses with zero indegree
        for (int i = 0; i < degree.size(); i++) {
            if (degree[i] == 0) {
                zeroDegree.push(i);
                numCourses--;
            }
        }

        // Processing nodes with zero indegree
        while (!zeroDegree.empty()) {
            int node = zeroDegree.front();
            zeroDegree.pop();
            for (int i = 0; i < graph[node].size(); i++) {
                int connectNode = graph[node][i];
                degree[connectNode]--;
                if (degree[connectNode] == 0) {
                    zeroDegree.push(connectNode);
                    numCourses--;
                }
            }
        }

        // If all courses have been processed, return true; otherwise, false
        return numCourses == 0;
    }
};

int main() {
    Solution sol;

    // Test case 1: No circular dependencies
    int numCourses1 = 4;
    vector<vector<int>> prerequisites1 = {{1, 0}, {2, 1}, {3, 2}};
    bool result1 = sol.canFinish(numCourses1, prerequisites1);
    cout << "Can finish courses (Test Case 1): " << (result1 ? "Yes" : "No") << endl;

    // Test case 2: One course with no prerequisites
    int numCourses2 = 2;
    vector<vector<int>> prerequisites2 = {{1, 0}};
    bool result2 = sol.canFinish(numCourses2, prerequisites2);
    cout << "Can finish courses (Test Case 2): " << (result2 ? "Yes" : "No") << endl;

    // Test case 3: Circular dependency
    int numCourses3 = 2;
    vector<vector<int>> prerequisites3 = {{0, 1}, {1, 0}};
    bool result3 = sol.canFinish(numCourses3, prerequisites3);
    cout << "Can finish courses (Test Case 3): " << (result3 ? "Yes" : "No") << endl;

    // Test case 4: No prerequisites (empty case)
    int numCourses4 = 3;
    vector<vector<int>> prerequisites4 = {};
    bool result4 = sol.canFinish(numCourses4, prerequisites4);
    cout << "Can finish courses (Test Case 4): " << (result4 ? "Yes" : "No") << endl;

    return 0;
}
