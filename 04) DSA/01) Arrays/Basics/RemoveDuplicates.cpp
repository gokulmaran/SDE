#include <iostream>
#include <vector>

using namespace std;
//link: https://leetcode.com/problems/remove-duplicates-from-sorted-array/description/
int removeDuplicates(vector<int>& nums) {
    if (nums.empty()) return 0; // Handle empty vector case
    
    int i = 0; // Index for the place to insert the next unique element
    for (int j = 1; j < nums.size(); j++) {
        if (nums[j] != nums[i]) {
            i++;
            nums[i] = nums[j];
        }
    }
    return i + 1; // Return the new length of the vector with unique elements
}

int main() {
    // Example vector with duplicates
    vector<int> nums = {1, 1, 2, 3, 3, 4, 5, 5, 6};
    
    // Calling the removeDuplicates function
    int newLength = removeDuplicates(nums);
    
    // Output the new length
    cout << "The length of the array with unique elements is: " << newLength << endl;
    
    // Output the array with unique elements
    cout << "Array with unique elements: ";
    for (int i = 0; i < newLength; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;
    
    return 0;
}
