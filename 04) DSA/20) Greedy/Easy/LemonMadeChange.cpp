#include <iostream>
#include <vector>

using namespace std;
//link: https://leetcode.com/problems/lemonade-change/
class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five = 0, ten = 0;
        for(int i = 0; i < bills.size(); i++) {
            if (bills[i] == 5) {
                five++;
            } else if (bills[i] == 10) {
                if (five < 1) {
                    return false;
                } else {
                    five--;
                    ten++;
                }
            } else { // bills[i] == 20
                if (five == 0 || (ten == 0 && five < 3)) {
                    return false;
                } else if (ten > 0) {
                    ten--;
                    five--;
                } else {
                    five -= 3;
                }
            }
        }
        return true;
    }
};

int main() {
    Solution solution;

    // Example 1
    vector<int> bills1 = {5, 5, 5, 10, 20};
    bool result1 = solution.lemonadeChange(bills1);
    cout << "Can give change for bills1? " << (result1 ? "Yes" : "No") << endl;

    // Example 2
    vector<int> bills2 = {5, 5, 10, 10, 20};
    bool result2 = solution.lemonadeChange(bills2);
    cout << "Can give change for bills2? " << (result2 ? "Yes" : "No") << endl;

    // Example 3
    vector<int> bills3 = {10, 10};
    bool result3 = solution.lemonadeChange(bills3);
    cout << "Can give change for bills3? " << (result3 ? "Yes" : "No") << endl;

    return 0;
}
