#include <iostream>
#include <vector>

using namespace std;
//Link: https://www.geeksforgeeks.org/problems/extended-euclidean-algorithm3848/1
// Define the Solution class with gcd function
class Solution{
public:
    int solve(int a, int b, int &x, int &y) {
        if (b == 0) {
            x = 1;
            y = 0;
            return a;
        }
        int x1, y1;
        int g = solve(b, a % b, x1, y1);
        x = y1;
        y = x1 - (a / b) * y1;
        return g;
    }

    vector<int> gcd(int a, int b) {
        int x1, y1;
        int g = solve(a, b, x1, y1);
        vector<int> ans = {g, x1, y1};
        return ans;
    }
};

int main() {
    Solution sol;
    
    // Example input values
    int a = 56, b = 15;
    
    // Get GCD and coefficients
    vector<int> result = sol.gcd(a, b);
    
    // Print the results
    cout << "GCD: " << result[0] << endl;
    cout << "x: " << result[1] << endl;
    cout << "y: " << result[2] << endl;
    
    return 0;
}
