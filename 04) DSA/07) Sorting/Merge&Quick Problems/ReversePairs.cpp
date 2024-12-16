#include <iostream>
#include <vector>
using namespace std;
//Link: https://leetcode.com/problems/reverse-pairs/
class Solution {
public:
    void merge(vector<int>& nums, int low, int mid, int high, int& cnt) {
        int j = mid + 1;
        for (int i = low; i <= mid; i++) {
            while (j <= high && nums[i] > 2 * (long long)nums[j]) {
                j++;
            }
            cnt += j - (mid + 1);
        }

        int size = high - low + 1;
        vector<int> temp(size, 0);
        int left = low, right = mid + 1, k = 0;
        while (left <= mid && right <= high) {
            if (nums[left] < nums[right]) {
                temp[k++] = nums[left++];
            } else {
                temp[k++] = nums[right++];
            }
        }
        while (left <= mid) {
            temp[k++] = nums[left++];
        }
        while (right <= high) {
            temp[k++] = nums[right++];
        }
        int m = 0;
        for (int i = low; i <= high; i++) {
            nums[i] = temp[m++];
        }
    }

    void mergeSort(vector<int>& nums, int low, int high, int& cnt) {
        if (low >= high) {
            return;
        }
        int mid = (low + high) >> 1;
        mergeSort(nums, low, mid, cnt);
        mergeSort(nums, mid + 1, high, cnt);
        merge(nums, low, mid, high, cnt);
    }

    int reversePairs(vector<int>& nums) {
        int reversePairscnt = 0;
        mergeSort(nums, 0, nums.size() - 1, reversePairscnt);
        return reversePairscnt;
    }
};

int main() {
    Solution sol;

    // Example input
    vector<int> nums = {1, 3, 2, 3, 1};

    // Call the reversePairs method
    int result = sol.reversePairs(nums);

    // Output the result
    cout << "The number of reverse pairs is: " << result << endl;

    return 0;
}
