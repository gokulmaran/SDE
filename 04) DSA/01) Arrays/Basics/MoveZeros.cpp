#include <iostream>
#include <vector>

using namespace std;
//Link:
// Function to move all zeros in the vector to the end while maintaining the order of non-zero elements
void moveZeroes(vector<int>& nums) {
    int n = nums.size(); // Get the size of the vector
    int j = 0; // Index for placing non-zero elements

    // Move all non-zero elements to the front
    for (int i = 0; i < n; i++) {
        if (nums[i] != 0) {
            nums[j++] = nums[i];
        }
    }

    // Fill the rest of the vector with zeros
    for (; j < n; j++) {
        nums[j] = 0;
    }
}

int main() {
    // Example vector with zeros
    vector<int> nums = {0, 1, 0, 3, 12, 0, 4};
    
    // Calling the moveZeroes function
    moveZeroes(nums);
    
    // Output the vector after moving zeros
    cout << "Array after moving zeroes: ";
    for (int num : nums) {
        cout << num << " "; // Print each element of the modified vector
    }
    cout << endl;

    return 0;
}
