#include <iostream>

using namespace std;

// Definition for singly-linked list node
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};
//Link: https://www.geeksforgeeks.org/problems/count-nodes-of-linked-list/1
// Class containing the getCount function
class Solution {
public:
    // Function to count nodes of a linked list.
    int getCount(Node* head) {
        Node* curr = head;
        int count = 0;
        while (curr != nullptr) {
            curr = curr->next;
            count++;
        }
        return count;
    }
};

// Function to print the linked list
void printList(Node* head) {
    while (head) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

// Main function to test getCount
int main() {
    // Create a linked list: 1 -> 2 -> 3 -> 4 -> 5 -> NULL
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    // Print the linked list
    cout << "Linked list: ";
    printList(head);

    // Create a Solution object and count the nodes
    Solution solution;
    int count = solution.getCount(head);

    // Print the number of nodes
    cout << "Number of nodes in the linked list: " << count << endl;

    // Free the allocated memory
    Node* temp;
    while (head) {
        temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
