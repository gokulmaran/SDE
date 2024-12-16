#include <iostream>
#include <bits/stdc++.h>
using namespace std;
//Link: https://leetcode.com/problems/next-greater-element-i/description/
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans(nums1.size(), -1);
        stack<int> st;
        unordered_map<int, int> m;
        for (int i = 0; i < nums2.size(); i++) {
            int ele = nums2[i];
            while (!st.empty() && ele > st.top()) {
                m[st.top()] = ele;
                st.pop();
            }
            st.push(ele);
        }

        for (int i = 0; i < nums1.size(); i++) {
            if (m.find(nums1[i]) != m.end()) {
                ans[i] = m[nums1[i]];
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;
    
    vector<int> nums1 = {4, 1, 2};
    vector<int> nums2 = {1, 3, 4, 2};
    
    vector<int> result = sol.nextGreaterElement(nums1, nums2);
    
    cout << "Next greater elements are: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}

