#include <iostream>

using namespace std;

// Definition for a doubly linked list node.
struct Node {
    int data;
    Node* next;
    Node* prev;
    Node(int val) : data(val), next(nullptr), prev(nullptr) {}
};
//Link: https://www.geeksforgeeks.org/problems/remove-duplicates-from-a-sorted-doubly-linked-list/0
// Function to insert a new node at the end of the doubly linked list
Node* insertEnd(Node* head, int data) {
    Node* newNode = new Node(data);
    if (!head) {
        return newNode;
    }
    Node* temp = head;
    while (temp->next) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
    return head;
}
// Function to print the doubly linked list
void printList(Node* head) {
    Node* temp = head;
    while (temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Function to delete the doubly linked list and free memory
void deleteList(Node* head) {
    while (head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

class Solution {
public:
    Node* removeDuplicates(Node* head) {
        Node* p = head;
        while (p != NULL) {
            while (p->next != NULL && p->data == p->next->data) {
                Node* temp = p->next;
                p->next = temp->next;
                if (temp->next) {
                    temp->next->prev = p;
                }
                delete temp; // Free memory
            }
            p = p->next;
        }
        return head;
    }
};

int main() {
    // Create a doubly linked list with duplicates
    Node* head = nullptr;
    head = insertEnd(head, 1);
    head = insertEnd(head, 1);
    head = insertEnd(head, 2);
    head = insertEnd(head, 3);
    head = insertEnd(head, 3);
    head = insertEnd(head, 4);

    // Print the original list
    cout << "Original list: ";
    printList(head);

    // Remove duplicates
    Solution solution;
    head = solution.removeDuplicates(head);

    // Print the list after removing duplicates
    cout << "List after removing duplicates: ";
    printList(head);

    // Clean up memory
    deleteList(head);

    return 0;
}
