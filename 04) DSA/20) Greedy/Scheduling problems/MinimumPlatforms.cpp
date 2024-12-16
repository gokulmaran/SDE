#include <iostream>
#include <algorithm>

using namespace std;
//link: https://www.geeksforgeeks.org/problems/minimum-platforms-1587115620/1
class Solution {
public:
    // Function to find the minimum number of platforms required at the
    // railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int n) {
        // Sort arrival and departure times
        sort(arr, arr + n);
        sort(dep, dep + n);
        
        int i = 1, j = 0, cnt = 1, ans = 1;
        
        // Traverse both arrays
        while (i < n && j < n) {
            if (arr[i] <= dep[j]) {
                cnt++;
                i++;
            } else {
                cnt--;
                j++;
            }
            ans = max(ans, cnt);
        }
        return ans;
    }
};

int main() {
    Solution solution;

    // Define the arrival and departure times of trains
    int arr[] = {10, 12, 5, 8, 14}; // Arrival times
    int dep[] = {11, 14, 7, 12, 16}; // Departure times
    int n = sizeof(arr) / sizeof(arr[0]);

    // Get the minimum number of platforms required
    int minPlatforms = solution.findPlatform(arr, dep, n);

    // Output the result
    cout << "Minimum number of platforms required: " << minPlatforms << endl;

    return 0;
}
