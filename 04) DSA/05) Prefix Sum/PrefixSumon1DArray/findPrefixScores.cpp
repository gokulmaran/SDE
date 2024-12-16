#include <iostream>
#include <vector>

using namespace std;
//link: https://leetcode.com/problems/find-the-score-of-all-prefixes-of-an-array/
typedef long long ll;

class Solution {
public:
    vector<ll> findPrefixScore(vector<int>& nums) {
        vector<ll> ans;
        ll maxi = 0LL;
        ll sum = 0LL;
        for (auto x : nums) {
            maxi = max(maxi, (ll)x);
            sum += (x + maxi);
            ans.push_back(sum);
        }
        return ans;
    }
};

int main() {
    Solution sol;

    // Test case 1
    vector<int> nums1 = {1, 2, 3, 4};
    vector<ll> result1 = sol.findPrefixScore(nums1);

    cout << "Prefix scores for test case 1: ";
    for (ll score : result1) {
        cout << score << " ";
    }
    cout << endl;

    // Test case 2
    vector<int> nums2 = {5, 6, 1, 7};
    vector<ll> result2 = sol.findPrefixScore(nums2);

    cout << "Prefix scores for test case 2: ";
    for (ll score : result2) {
        cout << score << " ";
    }
    cout << endl;

    return 0;
}
