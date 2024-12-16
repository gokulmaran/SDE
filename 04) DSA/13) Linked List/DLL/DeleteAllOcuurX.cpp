#include <iostream>

using namespace std;

// Definition for doubly-linked list node
struct Node {
    int data;
    Node* next;
    Node* prev;
    Node(int x) : data(x), next(nullptr), prev(nullptr) {}
};
//Link:https://www.geeksforgeeks.org/problems/delete-all-occurrences-of-a-given-key-in-a-doubly-linked-list/1
// Function to delete all occurrences of x from the doubly linked list
void deleteAllOccurOfX(Node** head_ref, int x) {
    Node* head = *head_ref;
    Node* curr = head;
    while (curr != nullptr) {
        if (curr->data == x) {
            // Handle the node deletion
            if (curr->prev != nullptr) {
                curr->prev->next = curr->next;
            } else {
                *head_ref = curr->next; // Update head if it's the node to delete
            }
            if (curr->next != nullptr) {
                curr->next->prev = curr->prev;
            }
            Node* temp = curr;
            curr = curr->next;
            delete temp; // Free memory
        } else {
            curr = curr->next;
        }
    }
}
// Function to print the doubly-linked list
void printDLL(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}



// Function to clean up the list
void deleteList(Node* head) {
    Node* temp;
    while (head != nullptr) {
        temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    // Create a doubly linked list 1 <-> 2 <-> 3 <-> 2 <-> 4 <-> 2
    Node* head = new Node(1);
    Node* second = new Node(2);
    Node* third = new Node(3);
    Node* fourth = new Node(2);
    Node* fifth = new Node(4);
    Node* sixth = new Node(2);

    head->next = second;
    second->prev = head;
    second->next = third;
    third->prev = second;
    third->next = fourth;
    fourth->prev = third;
    fourth->next = fifth;
    fifth->prev = fourth;
    fifth->next = sixth;
    sixth->prev = fifth;

    cout << "Original list: ";
    printDLL(head);

    // Delete all occurrences of 2
    deleteAllOccurOfX(&head, 2);

    cout << "List after deleting all occurrences of 2: ";
    printDLL(head);

    // Clean up the list
    deleteList(head);

    return 0;
}
