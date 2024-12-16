#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
//Link: https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/description/
ListNode* deleteMiddle(ListNode* head) {
    if (!head || !head->next) return NULL;

    ListNode* slow = head;
    ListNode* fast = head->next->next;

    while (fast && fast->next) {
        fast = fast->next->next;
        slow = slow->next;
    }

    ListNode* toDelete = slow->next;
    slow->next = slow->next->next;
    delete toDelete;
    return head;
}

void printList(ListNode* head) {
    while (head) {
        std::cout << head->val << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

int main() {
    // Create a linked list: 1 -> 2 -> 3 -> 4 -> 5
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    // Print the original list
    std::cout << "Original list: ";
    printList(head);

    // Delete the middle node
    head = deleteMiddle(head);

    // Print the modified list
    std::cout << "Modified list after deleting the middle node: ";
    printList(head);

    // Free allocated memory
    ListNode* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}

