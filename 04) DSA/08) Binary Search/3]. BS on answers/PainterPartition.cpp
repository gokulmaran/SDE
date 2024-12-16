#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;
//Link: https://www.naukri.com/code360/problems/painter-s-partition-problem_1089557

// Function to check if it's possible to allocate books such that
// no student reads more than 'mid' pages and the number of students does not exceed 'm'
bool possible(vector<int>& arr, int mid, int m) {
    int sum = 0;   // Sum of pages allocated to the current student
    int cnt = 1;   // Number of students needed
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] + sum <= mid) {
            sum += arr[i]; // Allocate pages to the current student
        } else {
            cnt++; // Allocate to the next student
            sum = arr[i]; // Start with the current book for the new student
        }
    }
    return cnt > m; // Return true if more than 'm' students are needed
}

// Function to find the minimum number of pages
int findPages(vector<int>& arr, int n, int m) {
    if (m > n) return -1; // If there are more students than books, allocation is not possible

    int s = *max_element(arr.begin(), arr.end()); // Minimum possible pages to be read by any student
    int e = accumulate(arr.begin(), arr.end(), 0); // Maximum possible pages (all books read by one student)

    while (s <= e) {
        int mid = (s + e) / 2;
        if (possible(arr, mid, m)) {
            s = mid + 1; // Try for a larger number of pages
        } else {
            e = mid - 1; // Try for a smaller number of pages
        }
    }
    return e; // Return the minimum pages required
}

// Function to find the largest minimum distance between cows
int findLargestMinDistance(vector<int> &boards, int k) {
    // 'k' is the number of cows and 'boards' is the list of board lengths
    return findPages(boards, boards.size(), k);
}

int main() {
    // Example test cases
    vector<vector<int>> testCases = {
        {12, 34, 67, 90}, // Board lengths
        {10, 20, 30, 40, 50}, // Board lengths
        {5, 10, 20, 30, 40, 50} // Board lengths
    };

    vector<int> kValues = {2, 2, 3}; // Number of cows (or students) for each test case

    for (int i = 0; i < testCases.size(); i++) {
        vector<int> boards = testCases[i];
        int k = kValues[i];
        int result = findLargestMinDistance(boards, k);
        cout << "For boards with lengths ";
        for (int length : boards) {
            cout << length << " ";
        }
        cout << "and " << k << " cows, the largest minimum distance is " << result << "." << endl;
    }

    return 0;
}
