#include <iostream>
#include <vector>

using namespace std;
//link: https://www.geeksforgeeks.org/problems/max-sum-subarray-of-size-k5313/1
class Solution {
public:
    long maximumSumSubarray(int k, vector<int>& arr, int n) {
        long maxi = 0, sum = 0;
        int i = 0;
        
        // Calculate the sum of the first window
        for (i = 0; i < k; i++) {
            sum += arr[i];
        }
        maxi = sum;
        
        // Slide the window across the array
        while (i < n) {
            sum += arr[i];
            sum -= arr[i - k];
            maxi = max(maxi, sum);
            i++;
        }
        
        return maxi;
    }
};

int main() {
    Solution solution;

    // Test case 1
    vector<int> arr1 = {1, 2, 3, 4, 5, 6};
    int k1 = 3;
    int n1 = arr1.size();
    cout << "Maximum sum of subarray of size " << k1 << " is: " << solution.maximumSumSubarray(k1, arr1, n1) << endl;

    // Test case 2
    vector<int> arr2 = {10, 20, 30, 40, 50};
    int k2 = 2;
    int n2 = arr2.size();
    cout << "Maximum sum of subarray of size " << k2 << " is: " << solution.maximumSumSubarray(k2, arr2, n2) << endl;

    // Test case 3
    vector<int> arr3 = {4, 2, 7, 1, 8, 3, 5};
    int k3 = 4;
    int n3 = arr3.size();
    cout << "Maximum sum of subarray of size " << k3 << " is: " << solution.maximumSumSubarray(k3, arr3, n3) << endl;

    return 0;
}
