#include <iostream>
#include <vector>
#include <deque>
using namespace std;
//LinK: https://www.geeksforgeeks.org/problems/first-negative-integer-in-every-window-of-size-k3345/1
vector<long long> printFirstNegativeInteger(long long int A[], long long int N, long long int K) {
    vector<long long> ans;
    deque<long long> negNo;
    
    long long i = 0, j = 0;
    
    while (j < N) {
        // Add negative numbers to the deque
        if (A[j] < 0) {
            negNo.push_back(A[j]);
        }
        
        // When the window size is reached
        if ((j - i + 1) == K) {
            if (!negNo.empty()) {
                ans.push_back(negNo.front());
                // Remove the element from deque if it is going out of the window
                if (A[i] == negNo.front()) {
                    negNo.pop_front();
                }
            } else {
                ans.push_back(0);
            }
            i++;
        }
        j++;
    }
    return ans;
}

int main() {
    // Example input
    long long int A[] = {-8, 2, 3, -6, 5, -4, 9};
    long long int N = sizeof(A) / sizeof(A[0]);
    long long int K = 3;

    // Get the first negative integer of each window of size K
    vector<long long> result = printFirstNegativeInteger(A, N, K);

    // Output the results
    cout << "First negative integers in each sliding window of size " << K << ": ";
    for (long long num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
