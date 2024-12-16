#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//Link: https://leetcode.com/problems/maximum-xor-with-an-element-from-array/
class Node {
public:
    Node* links[2];

    Node() {
        links[0] = NULL;
        links[1] = NULL;
    }

    bool ContainsKey(int bit) {
        return links[bit] != NULL;
    }

    Node* get(int bit) {
        return links[bit];
    }

    void put(int bit, Node* node) {
        links[bit] = node;
    }
};

class Trie {
public:
    Node* root;

    Trie() {
        root = new Node();
    }

    void insert(int num) {
        Node* node = root;
        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if (!(node->ContainsKey(bit))) {
                node->put(bit, new Node());
            }
            node = node->get(bit);
        }
    }

    int maxXor(int num) {
        Node* node = root;
        int maxx = 0;
        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if (node->ContainsKey(1 - bit)) {
                maxx = maxx | (1 << i);
                node = node->get(1 - bit);
            } else {
                node = node->get(bit);
            }
        }
        return maxx;
    }
};

class Solution {
public:
    vector<int> maximizeXor(vector<int> &nums, vector<vector<int>> &queries) {
        int n = nums.size();
        int q = queries.size();
        sort(nums.begin(), nums.end());

        vector<pair<int, pair<int, int>>> OfflineQueries;

        for (int i = 0; i < q; i++) {
            OfflineQueries.push_back({queries[i][1], {queries[i][0], i}});
        }

        sort(OfflineQueries.begin(), OfflineQueries.end());

        int index = 0;
        Trie trie;
        vector<int> ans(q);
        for (int i = 0; i < q; i++) {
            int Ai = OfflineQueries[i].first;
            int Xi = OfflineQueries[i].second.first;
            int Qindex = OfflineQueries[i].second.second;

            while (index < n && nums[index] <= Ai) {
                trie.insert(nums[index]);
                index++;
            }

            if (index == 0) {
                ans[Qindex] = -1;
            } else {
                ans[Qindex] = trie.maxXor(Xi);
            }
        }
        return ans;
    }
};

int main() {
    Solution solution;

    vector<int> nums = {3, 5, 7, 9, 11};
    vector<vector<int>> queries = {{3, 10}, {5, 14}, {7, 2}, {9, 6}, {11, 8}};

    vector<int> result = solution.maximizeXor(nums, queries);

    cout << "Results of maximizeXor queries:" << endl;
    for (int res : result) {
        cout << res << " ";
    }
    cout << endl;

    return 0;
}
