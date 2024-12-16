#include <iostream>
#include <vector>
#include <climits> // For INT_MIN

using namespace std;
//Link: https://www.geeksforgeeks.org/problems/largest-element-in-array4009/0

int largest(vector<int> &arr, int n, int ans = INT_MIN) {
    for(int &it : arr) 
        ans = max(ans, it);
    return ans;
}

int main() {
    // Example vector
    vector<int> arr = {3, 5, 7, 2, 8, 6};
    int n = arr.size();
    
    // Calling the largest function
    int result = largest(arr, n);
    
    // Output the result
    cout << "The largest element is: " << result << endl;
    
    return 0;
}
