#include <iostream>
#include <queue>
#include <stack>
using namespace std;
//link: https://www.geeksforgeeks.org/problems/reverse-first-k-elements-of-queue/1
queue<int> modifyQueue(queue<int> q, int k) {
    stack<int> s;
    int n = q.size();
    
    // Step 1: Push the first k elements into the stack
    for (int i = 0; i < k; i++) {
        s.push(q.front());
        q.pop();
    }
    
    // Step 2: Pop elements from the stack and push them back into the queue
    for (int j = 0; j < k; j++) {
        q.push(s.top());
        s.pop();
    }
    
    // Step 3: Move the remaining elements from the front of the queue to the end
    for (int a = 0; a < n - k; a++) {
        int b = q.front();
        q.push(b);
        q.pop();
    }
    
    return q;
}

int main() {
    // Initialize a queue with some values
    queue<int> q;
    for (int i = 1; i <= 6; i++) {
        q.push(i);
    }
    
    int k = 3; // Number of elements to reverse
    
    // Modify the queue
    queue<int> result = modifyQueue(q, k);
    
    // Print the modified queue
    cout << "Modified queue: ";
    while (!result.empty()) {
        cout << result.front() << " ";
        result.pop();
    }
    cout << endl;
    
    return 0;
}
