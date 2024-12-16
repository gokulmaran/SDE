#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
//link;https://leetcode.com/problems/fruit-into-baskets/description/
class Solution {
public:
    int totalFruit(vector<int>& arr) {
        int i = 0, j = 0, ans = 0;
        unordered_map<int, int> m;
        while (j < arr.size()) {
            m[arr[j]]++;
            while (m.size() > 2) {
                m[arr[i]]--;
                if (m[arr[i]] == 0) m.erase(arr[i]);
                i++;
            }
            ans = max(ans, j - i + 1);
            j++;
        }
        return ans;
    }
};

int main() {
    Solution solution;

    // Test case 1: General case with multiple fruit types
    vector<int> arr1 = {1, 2, 1, 2, 3, 1, 2, 3};
    int result1 = solution.totalFruit(arr1);
    cout << "Total number of fruits in longest subarray with at most 2 types: " << result1 << endl;

    // Test case 2: All fruits of one type
    vector<int> arr2 = {1, 1, 1, 1, 1};
    int result2 = solution.totalFruit(arr2);
    cout << "Total number of fruits in longest subarray with at most 2 types: " << result2 << endl;

    // Test case 3: Only two types of fruits
    vector<int> arr3 = {1, 2, 2, 1, 1, 2};
    int result3 = solution.totalFruit(arr3);
    cout << "Total number of fruits in longest subarray with at most 2 types: " << result3 << endl;

    // Test case 4: More than two types of fruits
    vector<int> arr4 = {1, 2, 3, 4, 1, 2, 3};
    int result4 = solution.totalFruit(arr4);
    cout << "Total number of fruits in longest subarray with at most 2 types: " << result4 << endl;

    // Test case 5: Empty array
    vector<int> arr5 = {};
    int result5 = solution.totalFruit(arr5);
    cout << "Total number of fruits in longest subarray with at most 2 types: " << result5 << endl;

    // Test case 6: Single element
    vector<int> arr6 = {1};
    int result6 = solution.totalFruit(arr6);
    cout << "Total number of fruits in longest subarray with at most 2 types: " << result6 << endl;

    return 0;
}
