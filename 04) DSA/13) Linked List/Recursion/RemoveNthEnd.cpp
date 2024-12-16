#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
//Link: https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/

ListNode *removeNthFromEnd(ListNode *head, int &n) {
    if (head == NULL) // if end
        return NULL;

    head->next = removeNthFromEnd(head->next, n); // set to the next node

    if (--n == 0) // do I need to remove this node
        return head->next;
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

    // Specify the position from the end to remove
    int n = 2;

    // Remove the nth node from the end
    head = removeNthFromEnd(head, n);

    // Print the modified list
    std::cout << "Modified list after removing " << n << "th node from the end: ";
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

