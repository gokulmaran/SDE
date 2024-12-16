#include <iostream>
#include <algorithm>

using namespace std;

struct Item {
    int value;
    int weight;
};
//Link: https://www.geeksforgeeks.org/problems/fractional-knapsack-1587115620/1
class Solution {
public:
    static bool comp(Item a, Item b) {
        return ((double)a.value / a.weight) > ((double)b.value / b.weight);
    }

    double fractionalKnapsack(int w, Item arr[], int n) {
        // Sort items by value/weight ratio
        sort(arr, arr + n, comp);
        
        int totalw = 0;
        double ans = 0.0;
        
        // Traverse sorted items
        for (int i = 0; i < n; i++) {
            if (totalw + arr[i].weight <= w) {
                ans += arr[i].value;
                totalw += arr[i].weight;
            } else {
                ans += ((double)arr[i].value / arr[i].weight) * (w - totalw);
                break;
            }
        }
        return ans;
    }
};

int main() {
    Solution solution;

    // Define number of items
    int n = 3;

    // Define items
    Item arr[] = {
        {60, 10},  // Value = 60, Weight = 10
        {100, 20}, // Value = 100, Weight = 20
        {120, 30}  // Value = 120, Weight = 30
    };

    // Define the capacity of the knapsack
    int w = 50;

    // Get the maximum value that can be accommodated in the knapsack
    double maxValue = solution.fractionalKnapsack(w, arr, n);

    // Output the result
    cout << "Maximum value in the knapsack = " << maxValue << endl;

    return 0;
}
