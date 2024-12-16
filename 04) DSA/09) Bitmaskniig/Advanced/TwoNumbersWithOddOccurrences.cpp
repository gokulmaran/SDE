#include <iostream>
#include <vector>

using namespace std;
//Link: https://www.geeksforgeeks.org/problems/two-numbers-with-odd-occurrences5846/1
class Solution {
public:
    vector<long long int> twoOddNum(long long int arr[], long long int n) {
        // Find XOR of all elements
        long long xr = 0;
        for (int i = 0; i < n; i++) {
            xr ^= arr[i];
        }
        
        // Find rightmost set bit
        int rightmost = (xr & (xr - 1)) ^ xr;
        
        // Separate into 2 buckets based on rightmost bit
        long long b1 = 0, b2 = 0;
        for (int i = 0; i < n; i++) {
            if (arr[i] & rightmost) {
                b1 ^= arr[i];
            } else {
                b2 ^= arr[i];
            }
        }
        
        if (b1 > b2) return {b1, b2};
        return {b2, b1};
    }
};

int main() {
    Solution sol;
    
    // Example 1
    long long arr1[] = {1, 2, 1, 3, 2, 5};
    long long n1 = sizeof(arr1) / sizeof(arr1[0]);
    vector<long long> result1 = sol.twoOddNum(arr1, n1);
    cout << "The two odd occurring numbers are: " << result1[0] << " and " << result1[1] << endl;

    // Example 2
    long long arr2[] = {4, 5, 6, 7, 8, 4, 5, 8};
    long long n2 = sizeof(arr2) / sizeof(arr2[0]);
    vector<long long> result2 = sol.twoOddNum(arr2, n2);
    cout << "The two odd occurring numbers are: " << result2[0] << " and " << result2[1] << endl;

    // Example 3
    long long arr3[] = {10, 20, 10, 30, 20, 40, 30, 50};
    long long n3 = sizeof(arr3) / sizeof(arr3[0]);
    vector<long long> result3 = sol.twoOddNum(arr3, n3);
    cout << "The two odd occurring numbers are: " << result3[0] << " and " << result3[1] << endl;

    return 0;
}
