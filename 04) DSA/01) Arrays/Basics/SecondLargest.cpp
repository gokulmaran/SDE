#include <iostream>
#include <vector>

using namespace std;
//Link: https://www.geeksforgeeks.org/problems/second-largest3735/1
int print2largest(vector<int> &arr) {
    int first = -1, second = -1;
    for(int i = 0; i < arr.size(); i++) {
        if(arr[i] > first) {
            second = first;
            first = arr[i];
        }
        else if(arr[i] > second && arr[i] < first) {
            second = arr[i];
        }
    }
    return second;
}

int main() {
    // Example vector
    vector<int> arr = {12, 35, 1, 10, 34, 1};
    
    // Calling the print2largest function
    int result = print2largest(arr);
    
    // Output the result
    if (result != -1) {
        cout << "The second largest element is: " << result << endl;
    } else {
        cout << "There is no second largest element." << endl;
    }
    
    return 0;
}
