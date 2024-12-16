#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;
//Link: https://www.naukri.com/code360/problems/allocate-books_1090540

// Function to check if it's possible to allocate books such that
// no student reads more than 'mid' pages and number of students does not exceed 'm'
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

int main() {
    // Example test cases
    vector<vector<int>> testCases = {
        {12, 34, 67, 90}, // Book pages
        {10, 20, 30, 40}, // Book pages
        {5, 10, 20, 30, 40, 50} // Book pages
    };

    vector<int> nValues = {4, 4, 6}; // Number of books in each test case
    vector<int> mValues = {2, 2, 3}; // Number of students in each test case

    for (int i = 0; i < testCases.size(); i++) {
        vector<int> arr = testCases[i];
        int n = nValues[i];
        int m = mValues[i];
        int result = findPages(arr, n, m);
        cout << "For " << n << " books and " << m << " students, the minimum number of pages is " << result << "." << endl;
    }

    return 0;
}
