#include <iostream>
#include <vector>
#include <algorithm> // For min and max functions
#include <climits>   // For INT_MAX

using namespace std;
//
// Function to find the maximum profit from stock prices
int maxProfit(vector<int>& prices) {
    int maxPro = 0;          // Initialize maximum profit
    int minPrice = INT_MAX;  // Initialize minimum price with a large value

    // Iterate through each price in the vector
    for (int i = 0; i < prices.size(); i++) {
        minPrice = min(minPrice, prices[i]);       // Update the minimum price
        maxPro = max(maxPro, prices[i] - minPrice); // Update the maximum profit
    }
    
    return maxPro; // Return the maximum profit
}

int main() {
    // Example vector with stock prices
    vector<int> prices = {7, 1, 5, 3, 6, 4};

    // Calling the maxProfit function to find the maximum profit
    int profit = maxProfit(prices);

    // Output the maximum profit
    cout << "The maximum profit is: " << profit << endl;

    return 0;
}
