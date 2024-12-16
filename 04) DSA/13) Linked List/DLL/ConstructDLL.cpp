#include <iostream>
#include <vector>

using namespace std;

// Definition for doubly-linked list node
struct Node {
    int val;
    Node* next;
    Node* prev;
    Node(int x) : val(x), next(nullptr), prev(nullptr) {}
};
//Link: https://www.geeksforgeeks.org/problems/introduction-to-doubly-linked-list/0
// Class containing the constructDLL function
class Solution {
public:
    Node* constructDLL(vector<int>& arr) {
        if (arr.empty()) return nullptr;
        
        Node* newhead = new Node(arr[0]);
        Node* temp = newhead;
        for (int i = 1; i < arr.size(); i++) {
            temp->next = new Node(arr[i]);
            temp->next->prev = temp;
            temp = temp->next;
        }
        return newhead;
    }
};

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
    Solution solution;
    
    // Example input
    vector<int> arr = {1, 2, 3, 4, 5};
    
    // Construct the doubly-linked list
    Node* head = solution.constructDLL(arr);

    // Print the doubly-linked list
    cout << "Doubly Linked List (Forward): ";
    printDLL(head);

    // Print the doubly-linked list in reverse
    cout << "Doubly Linked List (Reverse): ";
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
