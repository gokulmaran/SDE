#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <algorithm> // For reverse
using namespace std;
//Link: https://leetcode.com/problems/top-k-frequent-words/
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> mp;
        for (const string& s : words) {
            mp[s]++;
        }
        
        priority_queue<pair<int, string>> pq;

        for (const auto& it : mp) {
            pq.push({-it.second, it.first});
            if (pq.size() > k) {
                pq.pop();
            }
        }
        
        vector<string> ans;
        while (!pq.empty()) {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        reverse(ans.begin(), ans.end()); // Reverse to get the correct order

        return ans;
    }
};

int main() {
    Solution solution;

    // Example 1
    vector<string> words1 = {"i", "love", "leetcode", "i", "love", "coding"};
    int k1 = 2;
    vector<string> result1 = solution.topKFrequent(words1, k1);
    cout << "Top " << k1 << " frequent words (Example 1): ";
    for (const string& word : result1) {
        cout << word << " ";
    }
    cout << endl;

    // Example 2
    vector<string> words2 = {"the", "day", "is", "sunny", "the", "the", "the", "day"};
    int k2 = 2;
    vector<string> result2 = solution.topKFrequent(words2, k2);
    cout << "Top " << k2 << " frequent words (Example 2): ";
    for (const string& word : result2) {
        cout << word << " ";
    }
    cout << endl;

    return 0;
}
