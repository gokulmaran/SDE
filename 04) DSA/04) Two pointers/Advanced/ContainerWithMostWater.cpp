#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
//link: https://leetcode.com/problems/container-with-most-water/description/
class Solution {
public:
    // Function to calculate the maximum area of water that can be contained
    int maxArea(vector<int>& height) {
        int maxArea = 0; // Variable to store the maximum area
        int left = 0; // Left pointer
        int right = height.size() - 1; // Right pointer

        while (left < right) {
            // Calculate the area with the current left and right pointers
            maxArea = max(maxArea, (right - left) * min(height[left], height[right]));

            // Move the pointer that points to the shorter line
            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }

        return maxArea; // Return the maximum area
    }
};

int main() {
    Solution sol;

    // Test case 1
    vector<int> height1 = {1, 8, 6, 2, 5, 4, 8, 3, 7};

    // Test case 2
    vector<int> height2 = {1, 1};

    // Calculate the maximum area for each test case
    int result1 = sol.maxArea(height1);
    int result2 = sol.maxArea(height2);

    // Output the results
    cout << "Test case 1: Maximum area is " << result1 << endl;
    cout << "Test case 2: Maximum area is " << result2 << endl;

    return 0;
}
