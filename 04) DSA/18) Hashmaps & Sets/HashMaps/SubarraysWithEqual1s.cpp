#include <iostream>
#include <unordered_map>

using namespace std;
//Link: https://www.geeksforgeeks.org/problems/count-subarrays-with-equal-number-of-1s-and-0s-1587115620/1
class Solution {
public:
    // Function to count subarrays with equal number of 0s and 1s.
    long long int countSubarrWithEqualZeroAndOne(int arr[], int n) {
        unordered_map<int, int> m;
        int sum = 0;
        long long ans = 0;
        
        for (int i = 0; i < n; i++) {
            // Convert 0s to -1s
            if (arr[i] == 0) {
                arr[i] = -1;
            }
        }
        
        for (int i = 0; i < n; i++) {
            sum += arr[i];
            if (sum == 0) {
                ans++;
            }
            if (m.find(sum) != m.end()) {
                ans += m[sum];
            }
            m[sum]++;
        }
        
        return ans;
    }
};

int main() {
    Solution sol;
    
    // Example input
    int arr[] = {0, 1, 0, 1, 1, 0};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    // Calculate the number of subarrays with equal number of 0s and 1s
    long long result = sol.countSubarrWithEqualZeroAndOne(arr, n);
    
    // Output the result
    cout << "Number of subarrays with equal number of 0s and 1s: " << result << endl;

    return 0;
}
