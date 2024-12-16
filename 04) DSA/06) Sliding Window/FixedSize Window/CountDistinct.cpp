#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
//link: https://www.geeksforgeeks.org/problems/count-distinct-elements-in-every-window/1
class Solution {
public:
    vector<int> countDistinct(int a[], int n, int k) {
        unordered_map<int, int> m;
        vector<int> ans;
        int i = 0;

        // Process the first window of size k
        for (i = 0; i < k; i++) {
            m[a[i]]++;
        }
        ans.push_back(m.size());

        // Slide the window and update the count of distinct elements
        while (i < n) {
            m[a[i]]++;
            m[a[i - k]]--;
            if (m[a[i - k]] == 0) {
                m.erase(a[i - k]);
            }
            ans.push_back(m.size());
            i++;
        }
        return ans;
    }
};

int main() {
    Solution solution;

    // Test case 1
    int arr1[] = {1, 2, 1, 3, 4, 2, 3};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    int k1 = 4;
    vector<int> result1 = solution.countDistinct(arr1, n1, k1);
    cout << "Distinct counts for window size " << k1 << ": ";
    for (int count : result1) {
        cout << count << " ";
    }
    cout << endl;

    // Test case 2
    int arr2[] = {4, 4, 4, 4, 4, 4};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    int k2 = 3;
    vector<int> result2 = solution.countDistinct(arr2, n2, k2);
    cout << "Distinct counts for window size " << k2 << ": ";
    for (int count : result2) {
        cout << count << " ";
    }
    cout << endl;

    // Test case 3
    int arr3[] = {1, 2, 3, 4, 5, 6, 7};
    int n3 = sizeof(arr3) / sizeof(arr3[0]);
    int k3 = 5;
    vector<int> result3 = solution.countDistinct(arr3, n3, k3);
    cout << "Distinct counts for window size " << k3 << ": ";
