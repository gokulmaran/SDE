#include <iostream>

using namespace std;
//Link: 
// Definition for singly-linked list node
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Class containing the deleteNode function
class Solution {
public:
    void deleteNode(ListNode* node) {
        if (node == nullptr || node->next == nullptr) {
            // This should not happen based on the problem constraints
            return;
        }
        // Copy the value from the next node and skip over the next node
        node->val = node->next->val;
        ListNode* temp = node->next;
        node->next = node->next->next;
        delete temp; // Free the memory of the deleted node
    }
};

// Function to print the linked list
void printList(ListNode* head) {
    while (head) {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

// Main function to test deleteNode
int main() {
    // Create a linked list: 1 -> 2 -> 3 -> 4 -> 5 -> NULL
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    // Print the original list
    cout << "Original list: ";
    printList(head);

    // Create a Solution object and delete the node with value 3
    Solution solution;
    ListNode* nodeToDelete = head->next->next; // Node with value 3
    solution.deleteNode(nodeToDelete);

    // Print the list after deletion
    cout << "List after deleting node with value 3: ";
    printList(head);

    // Free the remaining allocated memory
    ListNode* temp;
    while (head) {
        temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
