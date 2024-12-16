#include <iostream>
#include <vector>
#include <algorithm> // For swap function

using namespace std;

//Link: https://leetcode.com/problems/next-permutation/description/
void nextPermutation(vector<int>& nums) {
    int i = nums.size() - 1, k = i;
    
    // Find the first decreasing element from the end
    while (i > 0 && nums[i - 1] >= nums[i])
        i--;
    
    // Reverse the sequence from i to the end of the array
    for (int j = i; j < k; j++, k--)
        swap(nums[j], nums[k]);
    
    // Swap the element at i-1 with the smallest element greater than it to its right
    if (i > 0) {
        k = i--;
        while (nums[k] <= nums[i])
            k++;
        swap(nums[i], nums[k]);
    }
}

int main() {
    // Example vector
    vector<int> nums = {1, 2, 3};

    // Calling the nextPermutation function to get the next permutation
    nextPermutation(nums);

    // Output the next permutation
    cout << "The next permutation is: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
