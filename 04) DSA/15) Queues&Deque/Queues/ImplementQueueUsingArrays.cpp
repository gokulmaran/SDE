#include <iostream>
using namespace std;
//Link: https://www.geeksforgeeks.org/problems/implement-queue-using-array/1
class MyQueue {
private:
    int arr[1000];
    int front;
    int rear;

public:
    MyQueue() : front(0), rear(0) {}

    // Function to push an element x in a queue.
    void push(int x) {
        arr[rear++] = x;
    }

    // Function to pop an element from the queue and return that element.
    int pop() {
        if (front == rear) {
            return -1; // Queue is empty
        }
        return arr[front++];
    }

    // Function to check if the queue is empty
    bool empty() {
        return front == rear;
    }

    // Function to get the front element of the queue
    int peek() {
        if (front == rear) {
            return -1; // Queue is empty
        }
        return arr[front];
    }
};

int main() {
    MyQueue q;

    // Test case 1: Push elements into the queue and pop them
    cout << "Push 1 into queue" << endl;
    q.push(1);

    cout << "Push 2 into queue" << endl;
    q.push(2);

    cout << "Push 3 into queue" << endl;
    q.push(3);

    cout << "Pop from queue: " << q.pop() << endl; // Expected Output: 1
    cout << "Pop from queue: " << q.pop() << endl; // Expected Output: 2

    // Test case 2: Check if the queue is empty
    cout << "Queue empty? " << (q.empty() ? "Yes" : "No") << endl; // Expected Output: No

    cout << "Push 4 into queue" << endl;
    q.push(4);

    cout << "Front element of queue: " << q.peek() << endl; // Expected Output: 3

    cout << "Pop from queue: " << q.pop() << endl; // Expected Output: 3
    cout << "Pop from queue: " << q.pop() << endl; // Expected Output: 4

    // Test case 3: Check if the queue is empty again
    cout << "Queue empty? " << (q.empty() ? "Yes" : "No") << endl; // Expected Output: Yes

    return 0;
}
