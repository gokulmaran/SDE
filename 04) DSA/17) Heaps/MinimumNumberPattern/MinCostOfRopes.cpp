#include <iostream>
#include <vector>
#include <queue>

using namespace std;
//Link: https://www.geeksforgeeks.org/problems/minimum-cost-of-ropes-1587115620/1
class Solution {
public:
    // Function to return the minimum cost of connecting the ropes.
    long long minCost(long long arr[], long long n) {
        priority_queue<long long, vector<long long>, greater<long long>> pq; 
        
        for(int i = 0; i < n; i++) {
            pq.push(arr[i]);
        }
        
        long long cost = 0;
        while(pq.size() > 1) {
            long long r1 = pq.top(); pq.pop();
            long long r2 = pq.top(); pq.pop();
            cost += r1 + r2;
            pq.push(r1 + r2);
        }
        
        return cost;
    }
};

int main() {
    Solution sol;

    // Example: array of rope lengths
    long long arr[] = {4, 3, 2, 6};
    long long n = sizeof(arr) / sizeof(arr[0]);

    long long result = sol.minCost(arr, n);

    cout << "Minimum cost of connecting ropes: " << result << endl;

    return 0;
}
