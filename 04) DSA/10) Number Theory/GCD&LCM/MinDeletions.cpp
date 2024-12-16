#include <bits/stdc++.h>
using namespace std;
//Link: https://www.codechef.com/problems/RD19?tab=statement
int main() {
    // Read number of test cases
    int t;
    cin >> t;
    
    while (t--) {
        // Read size of the array
        int n;
        cin >> n;
        int a[n];
        
        // Read array elements
        for (int i = 0; i < n; i++)
            cin >> a[i];
        
        int check = 0; // Variable to indicate if a valid pair is found
        
        // Check all pairs in the array
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                // Check if the GCD of the pair is 1
                if (gcd(a[i], a[j]) == 1) {
                    check = 1; // Pair found
                    break;
                }
            }
            if (check == 1)
                break; // Exit if pair is found
        }
        
        // Output result based on the presence of a valid pair
        if (check)
            cout << 0 << endl;
        else
            cout << -1 << endl;
    }
    
    return 0;
}
