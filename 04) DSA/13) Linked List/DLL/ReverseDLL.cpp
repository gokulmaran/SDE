#include <iostream>
#include <stack>

using namespace std;

// Definition for doubly-linked list node
struct Node {
    int data;
    Node* next;
    Node* prev;
    Node(int x) : data(x), next(nullptr), prev(nullptr) {}
};
//Link: https://www.geeksforgeeks.org/problems/delete-node-in-doubly-linked-list/1
class Solution {
public:
    Node* reverseDLL(Node* head) {
        stack<int> s;
        Node* temp = head;
        while (temp) {
            s.push(temp->data);
            temp = temp->next;
        }
        temp = head;
        while (temp) {
            temp->data = s.top();
            s.pop();
            temp = temp->next;
        }
        return head;
    }
};
// Function to print the doubly-linked list
void printDLL(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
// Function to print the doubly-linked list in reverse
void printReverseDLL(Node* head) {
    if (!head) return;

    // Go to the end of the list
    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }

    // Print in reverse
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->prev;
    }
    cout << endl;
}
int main() {
    // Create a doubly linked list 1 <-> 2 <-> 3 <-> 4 <-> 5
    Node* head = new Node(1);
    Node* second = new Node(2);
    Node* third = new Node(3);
    Node* fourth = new Node(4);
    Node* fifth = new Node(5);

    head->next = second;
    second->prev = head;
    second->next = third;
    third->prev = second;
    third->next = fourth;
    fourth->prev = third;
    fourth->next = fifth;
    fifth->prev = fourth;

    Solution sol;

    cout << "Original list: ";
    printDLL(head);

    // Reverse the doubly linked list
    head = sol.reverseDLL(head);

    cout << "List after reversal: ";
    printDLL(head);

    cout << "List in reverse order: ";
    printReverseDLL(head);

    // Clean up the list
    Node* temp;
    while (head != nullptr) {
        temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
