#include <iostream>
#include <vector>

using namespace std;
//link: https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/description/
class Solution {
public:
    // Function to find two indices such that their values sum up to the target
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0; 
        int right = numbers.size() - 1;
        
        while (left <= right) {
            int sum = numbers[left] + numbers[right];
            if (sum > target) {
                right--;
            } else if (sum < target) {
                left++;
            } else {
                return {left + 1, right + 1}; // 1-based index
            }
        }
        return {-1, -1}; // No solution found
    }
};

int main() {
    Solution sol;

    // Test case 1
    vector<int> numbers1 = {2, 7, 11, 15};
    int target1 = 9;

    // Test case 2
    vector<int> numbers2 = {1, 2, 3, 4, 5};
    int target2 = 8;

    // Find the indices of the two numbers that add up to the target
    vector<int> result1 = sol.twoSum(numbers1, target1);
    vector<int> result2 = sol.twoSum(numbers2, target2);

    // Output the results
    cout << "Indices of numbers that add up to " << target1 << " (test case 1): ";
    if (result1[0] != -1) {
        cout << result1[0] << " and " << result1[1] << endl;
    } else {
        cout << "No solution found." << endl;
    }

    cout << "Indices of numbers that add up to " << target2 << " (test case 2): ";
    if (result2[0] != -1) {
        cout << result2[0] << " and " << result2[1] << endl;
    } else {
        cout << "No solution found." << endl;
    }

    return 0;
}
