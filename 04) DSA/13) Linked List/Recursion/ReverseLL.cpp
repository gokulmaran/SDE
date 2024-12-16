#include <iostream>

using namespace std;

// Definition for singly-linked list node
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};
//Link: https://leetcode.com/problems/reverse-linked-list/description/
// Class containing the reverseList function
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;
        ListNode* prev = nullptr;
        ListNode* h2 = reverseList(head->next);
        head->next->next = head;
        head->next = prev;
        return h2;
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

// Main function to test reverseList
int main() {
    // Create a linked list: 1 -> 2 -> 3 -> 4 -> 5 -> NULL
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    // Print the original linked list
    cout << "Original list: ";
    printList(head);

    // Create a Solution object and reverse the linked list
    Solution solution;
    ListNode* reversedHead = solution.reverseList(head);

    // Print the reversed linked list
    cout << "Reversed list: ";
    printList(reversedHead);

    // Free the allocated memory
    ListNode* temp;
    while (reversedHead) {
        temp = reversedHead;
        reversedHead = reversedHead->next;
        delete temp;
    }

    return 0;
}
