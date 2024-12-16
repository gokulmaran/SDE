#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;
//Link: https://leetcode.com/problems/intersection-of-two-arrays/
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> m(nums1.begin(), nums1.end());
        vector<int> res;
        for (auto a : nums2) {
            if (m.count(a)) {
                res.push_back(a);
                m.erase(a);
            }
        }
        return res;
    }
};

int main() {
    Solution sol;

    // Example input
    vector<int> nums1 = {1, 2, 2, 1};
    vector<int> nums2 = {2, 2};

    // Calculate the intersection of nums1 and nums2
    vector<int> intersectionResult = sol.intersection(nums1, nums2);
    
    // Output the result
    cout << "Intersection: ";
    for (int num : intersectionResult) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
