#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
//Link: https://leetcode.com/problems/odd-even-linked-list/description/
//Approach
//   --> The idea is to split the linked list into 2 : one containing all odd nodes 
//     and other containing all even nodes. And finally, 
//      attach the even node linked list at the end of the odd node linked list.
//  -->To split the linked list into even nodes & odd nodes, we traverse the linked list and keep connecting the consecutive odd nodes and even nodes (to maintain the order of nodes) and save the pointer to the first even node.
// -->Finally, we insert all the even nodes at the end of the odd node list.

ListNode* oddEvenList(ListNode* head) {
    if (!head || !head->next || !head->next->next) return head;

    ListNode *odd = head;
    ListNode *even = head->next;
    ListNode *even_start = head->next;

    while (odd->next && even->next) {
        odd->next = even->next; // Connect all odds
        even->next = odd->next->next; // Connect all evens
        odd = odd->next;
        even = even->next;
    }
    odd->next = even_start; // Place the first even node after the last odd node
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

    // Rearrange the linked list
    head = oddEvenList(head);

    // Print the rearranged list
    std::cout << "Rearranged list: ";
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

