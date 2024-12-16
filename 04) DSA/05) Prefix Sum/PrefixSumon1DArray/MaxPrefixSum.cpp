#include <iostream>
#include <vector>
#include <climits>  // For INT_MIN

using namespace std;
//link: https://www.geeksforgeeks.org/problems/maximum-prefix-sum-for-a-given-range0227/1
class Solution {
public:
    vector<int> maxPrefixes(int a[], int L[], int R[], int N, int Q) {
        vector<int> sum;
        int j = 0;
        while (Q != 0) {
            int pre = 0;
            int maxi = INT_MIN;
            for (int i = L[j]; i <= R[j]; i++) {
                pre += a[i];
                maxi = max(maxi, pre);
            }
            j++;
            sum.push_back(maxi);
            Q--;
        }
        return sum;
    }
};

int main() {
    Solution sol;

    // Test case 1
    int a1[] = {1, 2, 3, 4, 5}; // Array of elements
    int L1[] = {0, 1, 2}; // Starting indices for queries
    int R1[] = {2, 3, 4}; // Ending indices for queries
    int N1 = 5; // Size of array a1
    int Q1 = 3; // Number of queries

    vector<int> result1 = sol.maxPrefixes(a1, L1, R1, N1, Q1);

    cout << "Max prefixes for test case 1: ";
    for (int value : result1) {
        cout << value << " ";
    }
    cout << endl;

    // Test case 2
    int a2[] = {5, -2, 3, 1, 4, 2}; // Array of elements
    int L2[] = {1, 2}; // Starting indices for queries
    int R2[] = {4, 5}; // Ending indices for queries
    int N2 = 6; // Size of array a2
    int Q2 = 2; // Number of queries

    vector<int> result2 = sol.maxPrefixes(a2, L2, R2, N2, Q2);

    cout << "Max prefixes for test case 2: ";
    for (int value : result2) {
        cout << value << " ";
    }
    cout << endl;

    return 0;
}
