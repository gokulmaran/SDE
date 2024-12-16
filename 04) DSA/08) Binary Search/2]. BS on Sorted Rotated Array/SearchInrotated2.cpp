#include <iostream>
#include <vector>
using namespace std;
//Link: https://leetcode.com/problems/search-in-rotated-sorted-array-ii/description/
class Solution {
public:
    bool search(vector<int>& arr, int target) {
        int s = 0, e = arr.size() - 1;
        while (s <= e) {
            int mid = s + (e - s) / 2;
            if (arr[mid] == target) {
                return true;
            }
            // Handle duplicates
            if (arr[s] == arr[mid] && arr[mid] == arr[e]) {
                s++;
                e--;
                continue;
            }
            // Left half sorted
            else if (arr[mid] >= arr[s]) {
                if (arr[s] <= target && target <= arr[mid]) {
                    e = mid - 1;
                } else {
                    s = mid + 1;
                }
            }
            // Right half sorted
            else {
                if (arr[mid] <= target && target <= arr[e]) {
                    s = mid + 1;
                } else {
                    e = mid - 1;
                }
            }
        }
        return false;
    }
};

int main() {
    Solution sol;

    // Example rotated sorted array with duplicates
    vector<int> arr = {2, 5, 6, 7, 0, 1, 2};

    // Target values to test
    vector<int> targets = {0, 3, 5, 7, 2, 8};

    // Testing search function
    for (int target : targets) {
        bool found = sol.search(arr, target);
        cout << "The target " << target << " is " << (found ? "found" : "not found") << " in the array." << endl;
    }

    return 0;
}
