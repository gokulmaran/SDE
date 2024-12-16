#include <iostream>
#include <vector>

using namespace std;
//link: https://www.geeksforgeeks.org/problems/-minimum-number-of-coins4426/1
class Solution {
public:
    vector<int> minPartition(int N) {
        vector<int> ans;
        vector<int> coins = {2000, 500, 200, 100, 50, 20, 10, 5, 2, 1};
        for (int coin : coins) {
            while (N >= coin) {
                ans.push_back(coin);
                N -= coin;
            }
        }
        return ans;
    }
};

int main() {
    Solution solution;

    // Define the amount N
    int N = 2897; // You can change this value to test different amounts

    // Get the minimum number of coins needed to make the amount N
    vector<int> result = solution.minPartition(N);

    // Output the result
    cout << "Coins needed to make " << N << " are: ";
    for (int coin : result) {
        cout << coin << " ";
    }
    cout << endl;

    return 0;
}
