#include <iostream>
#include <vector>

using namespace std;

//Link:https://leetcode.com/problems/rotate-array/description/  

void rotate(vector<int>& nums, int k) {
    int n = nums.size();
    vector<int> temp(n);
    for (int i = 0; i < n; i++) {
        temp[(i + k) % n] = nums[i];
    }
    nums = temp;
}

int main() {
    // Example vector
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
    int k = 3; // Number of positions to rotate the array

    // Calling the rotate function
    rotate(nums, k);

    // Output the rotated vector
    cout << "Rotated array: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
