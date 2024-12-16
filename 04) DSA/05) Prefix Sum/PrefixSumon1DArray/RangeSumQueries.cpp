#include <iostream>
#include <vector>

using namespace std;
//link: https://leetcode.com/problems/range-sum-query-immutable/description/
class NumArray {
public:
    vector<int> a; // Vector to store prefix sums

    // Constructor to initialize prefix sums
    NumArray(vector<int>& nums) {
        if (nums.empty()) return; // Handle edge case for empty input
        a.push_back(nums[0]);
        for (int i = 1; i < nums.size(); i++) {
            a.push_back(nums[i] + a[i - 1]);
        }
    }
    
    // Function to get the sum of the range [left, right]
    int sumRange(int left, int right) {
        if (left == 0)
            return a[right];
        return a[right] - a[left - 1];
    }
};

int main() {
    // Test case 1
    vector<int> nums1 = {1, 2, 3, 4, 5};
    NumArray* obj1 = new NumArray(nums1);

    cout << "Sum range (0, 2): " << obj1->sumRange(0, 2) << endl; // Expected output: 6 (1+2+3)
    cout << "Sum range (2, 4): " << obj1->sumRange(2, 4) << endl; // Expected output: 12 (3+4+5)
    cout << "Sum range (1, 3): " << obj1->sumRange(1, 3) << endl; // Expected output: 9 (2+3+4)

    // Test case 2
    vector<int> nums2 = {5, 6, 7, 8, 9};
    NumArray* obj2 = new NumArray(nums2);

    cout << "Sum range (1, 4): " << obj2->sumRange(1, 4) << endl; // Expected output: 30 (6+7+8+9)
    cout << "Sum range (0, 1): " << obj2->sumRange(0, 1) << endl; // Expected output: 11 (5+6)
    cout << "Sum range (2, 2): " << obj2->sumRange(2, 2) << endl; // Expected output: 7

    // Clean up
    delete obj1;
    delete obj2;

    return 0;
}
