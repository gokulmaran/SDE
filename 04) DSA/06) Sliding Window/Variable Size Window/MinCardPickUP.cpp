#include <iostream>
#include <vector>
#include <unordered_map>
#include <climits>

using namespace std;
//link: https://leetcode.com/problems/minimum-consecutive-cards-to-pick-up/description/
class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        int i = 0, ans = INT_MAX;
        unordered_map<int, int> m;
        while (i < cards.size()) {
            if (m.find(cards[i]) != m.end()) {
                ans = min(ans, i - m[cards[i]] + 1);
            }
            m[cards[i]] = i;
            i++;
        }
        return ans == INT_MAX ? -1 : ans;
    }
};

int main() {
    Solution solution;

    // Test case 1
    vector<int> cards1 = {1, 2, 3, 4, 5, 1};
    int result1 = solution.minimumCardPickup(cards1);
    cout << "Minimum card pickup for cards {1, 2, 3, 4, 5, 1}: " << result1 << endl;

    // Test case 2
    vector<int> cards2 = {1, 2, 3, 4, 5};
    int result2 = solution.minimumCardPickup(cards2);
    cout << "Minimum card pickup for cards {1, 2, 3, 4, 5}: " << result2 << endl;

    // Test case 3
    vector<int> cards3 = {1, 2, 3, 1, 4, 5, 6};
    int result3 = solution.minimumCardPickup(cards3);
    cout << "Minimum card pickup for cards {1, 2, 3, 1, 4, 5, 6}: " << result3 << endl;

    // Test case 4
    vector<int> cards4 = {1, 2, 3, 4, 2, 1};
    int result4 = solution.minimumCardPickup(cards4);
    cout << "Minimum card pickup for cards {1, 2, 3, 4, 2, 1}: " << result4 << endl;

    // Test case 5
    vector<int> cards5 = {1, 2, 3, 4, 5, 6, 7, 8};
    int result5 = solution.minimumCardPickup(cards5);
    cout << "Minimum card pickup for cards {1, 2, 3, 4, 5, 6, 7, 8}: " << result5 << endl;

    return 0;
}
