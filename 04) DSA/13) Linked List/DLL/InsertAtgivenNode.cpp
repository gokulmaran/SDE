#include <iostream>

using namespace std;
//Link: https://www.geeksforgeeks.org/problems/insert-a-node-in-doubly-linked-list/1
// Definition for doubly-linked list node
struct Node {
    int val;
    Node* next;
    Node* prev;
    Node(int x) : val(x), next(nullptr), prev(nullptr) {}
};
// Function to add a node at a specific position
void addNode(Node *head, int pos, int data)
{
   Node* temp = head;
   Node* newNode = new Node(data);

   // Traverse to the position before where the new node will be inserted
   for (int i = 0; i < pos && temp != nullptr; i++) {
       temp = temp->next;
   }

   if (temp == nullptr) {
       // Position is out of bounds
       delete newNode;
       cout << "Position out of bounds" << endl;
       return;
   }

   // Insert the new node
   if (temp->next == nullptr) {
       // Insert at the end
       temp->next = newNode;
       newNode->prev = temp;
       newNode->next = nullptr;
   } else {
       // Insert in between or at the start
       newNode->prev = temp;
       newNode->next = temp->next;
       temp->next->prev = newNode;
       temp->next = newNode;
   }
}
// Function to print the doubly-linked list
void printDLL(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->val << " ";
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
        cout << temp->val << " ";
        temp = temp->prev;
    }
    cout << endl;
}

int main() {
    // Create initial doubly-linked list
    Node* head = new Node(1);
    Node* second = new Node(2);
    Node* third = new Node(3);
    head->next = second;
    second->prev = head;
    second->next = third;
    third->prev = second;
    third->next = nullptr;

    cout << "Original list: ";
    printDLL(head);

    // Insert new nodes
    addNode(head, 1, 4); // Insert 4 at position 1
    addNode(head, 0, 5); // Insert 5 at position 0
    addNode(head, 4, 6); // Insert 6 at position 4

    cout << "List after adding nodes: ";
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
