#include <iostream>
#include <vector>
#include <map>

using namespace std;
//Link: https://www.geeksforgeeks.org/problems/zero-sum-subarrays1825/1
class Solution {
public:
    // Function to count subarrays with sum equal to 0.
    long long int findSubarray(vector<long long int> &arr, int n) {
        long long int result = 0;
        map<long long int, int> m;
        long long int sum = 0, ans = 0;
        m[0] = 1; // To handle the case when subarray itself is zero
        for (int i = 0; i < n; i++) {
            sum += arr[i];
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
    vector<long long int> arr = {1, -1, 2, -2, 1};
    int n = arr.size();

    // Calculate the number of subarrays with sum equal to 0
    long long int result = sol.findSubarray(arr, n);

    // Output the result
    cout << "Number of subarrays with sum equal to 0: " << result << endl;

    return 0;
}
