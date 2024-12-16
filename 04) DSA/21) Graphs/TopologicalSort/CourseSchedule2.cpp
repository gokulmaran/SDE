#include <iostream>
#include <vector>
#include <functional>

using namespace std;
//Link: https://leetcode.com/problems/course-schedule-ii/description/
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        // Initializing 2D graph
        vector<vector<int>> graph(numCourses);
        vector<int> result, indegree(numCourses);

        // Building the graph and computing indegree
        for (auto& prereq : prerequisites) {
            graph[prereq[1]].push_back(prereq[0]);
            indegree[prereq[0]]++;
        }

        // DFS function to process nodes
        function<void(int)> dfs = [&](int current) {
            result.push_back(current);
            indegree[current] = -1; // Mark as visited

            for (auto nextCourse : graph[current]) {
                if (--indegree[nextCourse] == 0) {
                    dfs(nextCourse);
                }
            }
        };

        // Start DFS from nodes with zero indegree
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) {
                dfs(i);
            }
        }

        // Check if result contains all courses
        if (result.size() == numCourses) return result;
        return {};
    }
};

int main() {
    Solution sol;

    // Test case 1
    int numCourses1 = 4;
    vector<vector<int>> prerequisites1 = {{1, 0}, {2, 1}, {3, 2}};
    vector<int> order1 = sol.findOrder(numCourses1, prerequisites1);
    cout << "Order of courses (Test Case 1): ";
    for (int course : order1) {
        cout << course << " ";
    }
    cout << endl;

    // Test case 2
    int numCourses2 = 2;
    vector<vector<int>> prerequisites2 = {{1, 0}};
    vector<int> order2 = sol.findOrder(numCourses2, prerequisites2);
    cout << "Order of courses (Test Case 2): ";
    for (int course : order2) {
        cout << course << " ";
    }
    cout << endl;

    // Test case 3: No valid order (circular dependency)
    int numCourses3 = 2;
    vector<vector<int>> prerequisites3 = {{0, 1}, {1, 0}};
    vector<int> order3 = sol.findOrder(numCourses3, prerequisites3);
    cout << "Order of courses (Test Case 3): ";
    if (order3.empty()) {
        cout << "No valid order (circular dependency)" << endl;
    } else {
        for (int course : order3) {
            cout << course << " ";
        }
        cout << endl;
    }

    return 0;
}
