#include <iostream>

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};
//Link: https://leetcode.com/problems/add-two-numbers/description/

// Function to add two numbers represented by linked lists
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    if (!l1 && !l2) return nullptr;
    else if (!l1) return l2;
    else if (!l2) return l1;

    int a = l1->val + l2->val;
    ListNode* p = new ListNode(a % 10);
    p->next = addTwoNumbers(l1->next, l2->next);
    if (a >= 10) {
        p->next = addTwoNumbers(p->next, new ListNode(1));
    }
    return p;
}

// Helper function to print the linked list
void printList(ListNode* node) {
    while (node) {
        std::cout << node->val;
        if (node->next) std::cout << " -> ";
        node = node->next;
    }
    std::cout << std::endl;
}

// Main function to test addTwoNumbers
int main() {
    // Creating first linked list: 2 -> 4 -> 3 (represents 342)
    ListNode* l1 = new ListNode(2);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(3);

    // Creating second linked list: 5 -> 6 -> 4 (represents 465)
    ListNode* l2 = new ListNode(5);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(4);

    // Adding two numbers
    ListNode* result = addTwoNumbers(l1, l2);

    // Printing the result
    std::cout << "Result: ";
    printList(result);

    // Clean up memory
    // (In practice, you should implement a function to delete the list nodes)

    return 0;
}

