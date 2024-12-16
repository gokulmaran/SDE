#include <iostream>
#include <vector>
using namespace std;
//link: https://www.geeksforgeeks.org/problems/find-element-occuring-once-when-all-other-are-present-thrice/1
class Solution {
public:
    int singleElement(int arr[], int N) {
        int one = 0, two = 0;
        for (int i = 0; i < N; i++) {
            one = (one ^ arr[i]) & ~two;
            two = (two ^ arr[i]) & ~one;
        }
        return one;
    }
};

int main() {
    Solution sol;
    
    // Example 1
    int arr1[] = {2, 2, 3, 2};
    int N1 = sizeof(arr1) / sizeof(arr1[0]);
    cout << "Single element in arr1: " << sol.singleElement(arr1, N1) << endl; // Output: 3
    
    // Example 2
    int arr2[] = {0, 1, 0, 1, 0, 1, 99};
    int N2 = sizeof(arr2) / sizeof(arr2[0]);
    cout << "Single element in arr2: " << sol.singleElement(arr2, N2) << endl; // Output: 99

    return 0;
}
