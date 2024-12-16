#include <iostream>
#include <bits/stdc++.h>
using namespace std;
//Link: https://leetcode.com/problems/largest-rectangle-in-histogram/description/

// Function to find the largest rectangle area in a histogram
int largestRectangleArea(vector<int>& heights) {
    stack<pair<int, int>> st;
    heights.push_back(0);  // Append a zero to handle any remaining bars in the stack

    int maxArea = 0;
    for (int i = 0; i < heights.size(); i++) {
        int start = i;
        // Pop from stack while the current height is less than the height at the stack's top
        while (!st.empty() && st.top().second > heights[i]) {
            auto [idx, height] = st.top();
            st.pop();
            maxArea = max(maxArea, height * (i - idx));
            start = idx;
        }
        // Push current index and height onto the stack
        st.push({start, heights[i]});
    }
    return maxArea;
}

int main() {
    // Example histogram heights
    vector<int> heights = {2, 1, 5, 6, 2, 3};
    
    // Compute the largest rectangle area
    int area = largestRectangleArea(heights);
    
    // Print the result
    cout << "Largest Rectangle Area: " << area << endl;
    
    return 0;
}

