#include <iostream>
#include <utility> // For std::pair

using namespace std;
//Link: https://www.geeksforgeeks.org/problems/swap-two-numbers3844/1
class Solution {
public:
    pair<int, int> get(int a, int b) {
        // Swap values using bitwise XOR
        a = a ^ b;
        b = a ^ b;
        a = a ^ b;
        return {a, b};
    }
};

int main() {
    Solution sol;

    // Test case 1
    int a1 = 5, b1 = 10;
    pair<int, int> result1 = sol.get(a1, b1);
    cout << "Swapped values: " << result1.first << " " << result1.second << endl;

    // Test case 2
    int a2 = 15, b2 = 25;
    pair<int, int> result2 = sol.get(a2, b2);
    cout << "Swapped values: " << result2.first << " " << result2.second << endl;

    // Test case 3
    int a3 = 0, b3 = 1;
    pair<int, int> result3 = sol.get(a3, b3);
    cout << "Swapped values: " << result3.first << " " << result3.second << endl;

    return 0;
}
