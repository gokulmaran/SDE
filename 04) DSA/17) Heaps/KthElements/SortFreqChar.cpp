#include <iostream>
#include <string>
#include <unordered_map>
#include <queue>
using namespace std;
//Link: https://leetcode.com/problems/sort-characters-by-frequency/
class Solution {
public:
    string frequencySort(string s) {
        // Frequency map
        unordered_map<char, int> m;
        for (char c : s) {
            m[c]++;
        }

        // Max heap (priority queue)
        priority_queue<pair<int, char>> pq;
        for (const auto& it : m) {
            pq.push({it.second, it.first});
        }

        // Build the result string
        string t;
        while (!pq.empty()) {
            int freq = pq.top().first;
            char ch = pq.top().second;
            pq.pop();
            t.append(freq, ch);
        }
        return t;
    }
};

int main() {
    Solution solution;

    // Example 1
    string s1 = "tree";
    string result1 = solution.frequencySort(s1);
    cout << "Frequency sorted string (Example 1): " << result1 << endl;

    // Example 2
    string s2 = "cccaaa";
    string result2 = solution.frequencySort(s2);
    cout << "Frequency sorted string (Example 2): " << result2 << endl;

    // Example 3
    string s3 = "Aabb";
    string result3 = solution.frequencySort(s3);
    cout << "Frequency sorted string (Example 3): " << result3 << endl;

    return 0;
}
