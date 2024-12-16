#include <iostream>
#include <vector>
using namespace std;
//Link: https://www.geeksforgeeks.org/problems/inversion-of-array-1587115620/1
class Solution {
public:
    // Function to count inversions in the array.
    long long c = 0;

    void merge(long long arr[], long long low, long long mid, long long high) {
        vector<long long> temp;
        long long left = low;
        long long right = mid + 1;

        while (left <= mid && right <= high) {
            if (arr[left] <= arr[right]) {
                temp.push_back(arr[left]);
                left++;
            } else {
                temp.push_back(arr[right]);
                c = c + (mid - left + 1);
                right++;
            }
        }
        while (left <= mid) {
            temp.push_back(arr[left]);
            left++;
        }
        while (right <= high) {
            temp.push_back(arr[right]);
            right++;
        }
        for (long long i = low; i <= high; i++) {
            arr[i] = temp[i - low];
        }
    }

    void mergesort(long long arr[], long long start, long long end) {
        if (start == end) return;
        long long mid = (start + end) / 2;
        mergesort(arr, start, mid);
        mergesort(arr, mid + 1, end);
        merge(arr, start, mid, end);
    }

    long long int inversionCount(long long arr[], long long N) {
        mergesort(arr, 0, N - 1);
        return c;
    }
};

int main() {
    Solution sol;

    // Example input
    long long arr[] = {2, 3, 8, 6, 1};
    long long N = sizeof(arr) / sizeof(arr[0]);

    // Call the inversionCount method
    long long result = sol.inversionCount(arr, N);

    // Output the result
    cout << "The number of inversions is: " << result << endl;

    return 0;
}
