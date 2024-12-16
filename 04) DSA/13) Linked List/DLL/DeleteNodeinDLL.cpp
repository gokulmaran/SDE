#include <iostream>

using namespace std;
//Link: https://www.geeksforgeeks.org/problems/delete-node-in-doubly-linked-list/1
// Definition for doubly-linked list node
struct Node {
    int val;
    Node* next;
    Node* prev;
    Node(int x) : val(x), next(nullptr), prev(nullptr) {}
};

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

// Function to print the doubly-linked list
void printDLL(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}

class Solution {
public:
    Node* deleteNode(Node* head, int x) {
        if (x == 1) {
            head = head->next;
            if (head) {
                head->prev = nullptr;
            }
            return head;
        }

        int cnt = 1;
        Node* temp = head;
        while (temp && cnt != x) {
            temp = temp->next;
            cnt++;
        }
        if (!temp) return head;

        if (temp->prev) {
            temp->prev->next = temp->next;
        }
        if (temp->next) {
            temp->next->prev = temp->prev;
        }
        delete temp;
        return head;
    }
};

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

    // Delete node at position 3
    head = sol.deleteNode(head, 3);

    cout << "List after deleting node at position 3: ";
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
