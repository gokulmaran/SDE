#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
//Link: https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold/description/
class Solution {
public:
    // Function to compute the sum of ceiling divisions by a given divisor
    int check(int mid, vector<int>& nums, int k) {
        int total = 0;
        for (int num : nums) {
            total += ceil((double)num / (double)mid);
        }
        return total;
    }

    // Function to find the smallest divisor
    int smallestDivisor(vector<int>& nums, int threshold) {
        int s = 1;
        int e = *max_element(nums.begin(), nums.end());
        while (s <= e) {
            int mid = (s + e) / 2;
            int num = check(mid, nums, threshold);
            if (num <= threshold) {
                e = mid - 1;
            } else {
                s = mid + 1;
            }
        }
        return s;
    }
};

int main() {
    Solution sol;

    // Example test cases
    vector<pair<vector<int>, int>> testCases = {
        {{1, 2, 5, 9}, 6},  // Expected output: 5
        {{44, 22, 33, 11}, 5},  // Expected output: 22
        {{21212, 10101, 12121}, 100000},  // Expected output: 1
        {{2, 3, 5, 7, 11}, 10},  // Expected output: 3
        {{1, 1, 1, 1, 1}, 3}  // Expected output: 1
    };

    // Testing smallestDivisor function
    for (const auto& testCase : testCases) {
        vector<int> nums = testCase.first;
        int threshold = testCase.second;
        int result = sol.smallestDivisor(nums, threshold);
        cout << "For nums: ";
        for (int num : nums) {
            cout << num << " ";
        }
        cout << "and threshold = " << threshold << ", the smallest divisor is " << result << "." << endl;
    }

    return 0;
}
