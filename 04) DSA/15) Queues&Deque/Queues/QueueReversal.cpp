#include <iostream>
#include <queue>
#include <stack>

using namespace std;
//Link: https://www.geeksforgeeks.org/problems/queue-reversal/1
class Solution {
public:
    // Function to reverse the elements of the queue
    queue<int> rev(queue<int> q) {
        stack<int> s;
        
        // Move all elements from the queue to the stack
        while (!q.empty()) {
            s.push(q.front());
            q.pop();
        }
        
        // Move all elements from the stack back to the queue
        queue<int> q1;
        while (!s.empty()) {
            q1.push(s.top());
            s.pop();
        }
        
        return q1;
    }
};

int main() {
    Solution sol;
    
    // Create a queue and populate it with some values
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);

    cout << "Original queue: ";
    // Print the original queue
    queue<int> temp = q;
    while (!temp.empty()) {
        cout << temp.front() << " ";
        temp.pop();
    }
    cout << endl;

    // Reverse the queue using the rev function
    queue<int> reversedQueue = sol.rev(q);

    cout << "Reversed queue: ";
    // Print the reversed queue
    while (!reversedQueue.empty()) {
        cout << reversedQueue.front() << " ";
        reversedQueue.pop();
    }
    cout << endl;

    return 0;
}
