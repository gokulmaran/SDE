#include <iostream>
#include <vector>
#include <string>
#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;
//Link: https://leetcode.com/problems/accounts-merge/
class Solution {
public:
    vector<int> parent;

    int find_set(int x) {
        if (parent[x] == x) return x;
        return parent[x] = find_set(parent[x]); // Path compression
    }

    void make_union(int x, int y) {
        int a = find_set(x);
        int b = find_set(y);
        if (a != b) {
            parent[a] = b; // Union by linking
        }
    }

    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        parent.resize(n);
        unordered_map<string, int> emailtoId;

        // Initialize Union-Find structure
        for (int i = 0; i < n; i++) {
            parent[i] = i; // Each account is its own parent initially
            for (int j = 1; j < accounts[i].size(); j++) {
                if (emailtoId.find(accounts[i][j]) != emailtoId.end()) {
                    make_union(emailtoId[accounts[i][j]], i); // Union accounts with the same email
                } else {
                    emailtoId[accounts[i][j]] = parent[i]; // Map email to the current account index
                }
            }
        }

        unordered_map<int, vector<string>> newaccounts;
        for (auto it : emailtoId) {
            newaccounts[find_set(it.second)].push_back(it.first); // Collect emails for each root account
        }

        vector<vector<string>> ans;
        for (auto& it : newaccounts) {
            auto& emails = it.second;
            sort(emails.begin(), emails.end()); // Sort emails
            emails.insert(emails.begin(), accounts[it.first][0]); // Insert account name
            ans.push_back(emails); // Add to result
        }

        return ans;
    }
};

int main() {
    // Create an instance of Solution
    Solution sol;

    // Define test case
    vector<vector<string>> accounts = {
        {"John", "johnsmith@mail.com", "john00@mail.com"},
        {"John", "johnnybravo@mail.com"},
        {"Mary", "mary@mail.com"},
        {"John", "johnsmith@mail.com", "john_newyork@mail.com"}
    };

    // Call accountsMerge function
    vector<vector<string>> result = sol.accountsMerge(accounts);

    // Print the result
    for (const auto& account : result) {
        for (const auto& detail : account) {
            cout << detail << " ";
        }
        cout << endl;
    }

    return 0;
}
