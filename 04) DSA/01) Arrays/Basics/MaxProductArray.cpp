#include <iostream>
#include <vector>
#include <climits> // For INT_MIN

using namespace std;

// Link:https://www.geeksforgeeks.org/problems/maximum-product-subarray3604/1
long long maxProduct(vector<int> arr, int n) {
    long long ans = INT_MIN;
    long long lefttoright = 1;
    long long righttoleft = 1;

    // Traverse the array from left to right and right to left
    for (int i = 0; i < n; i++) {
        if (lefttoright == 0) {
            lefttoright = 1;
        }
        if (righttoleft == 0) {
            righttoleft = 1;
        }

        // Update the product for both directions
        lefttoright *= arr[i];
        righttoleft *= arr[(n - 1) - i];

        // Update the answer with the maximum product found
        ans = max(ans, max(lefttoright, righttoleft));
    }

    return ans;
}

int main() {
    // Example vector with integers
    vector<int> arr = {2, 3, -2, 4, -1};
    int n = arr.size(); // Size of the vector

    // Calling the maxProduct function to find the maximum product of a contiguous subarray
    long long result = maxProduct(arr, n);

    // Output the result
    cout << "The maximum product of a contiguous subarray is: " << result << endl;

    return 0;
}
