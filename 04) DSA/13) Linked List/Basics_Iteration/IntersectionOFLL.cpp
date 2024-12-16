#include <iostream>
#include <unordered_map>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
//Link: https://leetcode.com/problems/intersection-of-two-linked-lists/description/

ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
    std::unordered_map<ListNode*, int> m;
    while (headA != NULL) {
        m[headA]++;
        headA = headA->next;
    }
    while (headB != NULL) {
        if (m[headB] > 0) {
            return headB;
        }
        headB = headB->next;
    }
    return nullptr;
}

void printList(ListNode* head) {
    while (head) {
        std::cout << head->val << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

int main() {
    // Create two intersecting linked lists
    // List A: 4 -> 1 -> 8 -> 4 -> 5
    // List B: 5 -> 6 -> 1 -> 8 -> 4 -> 5
    ListNode* intersect = new ListNode(8);
    intersect->next = new ListNode(4);
    intersect->next->next = new ListNode(5);

    ListNode* headA = new ListNode(4);
    headA->next = new ListNode(1);
    headA->next->next = intersect;

    ListNode* headB = new ListNode(5);
    headB->next = new ListNode(6);
    headB->next->next = new ListNode(1);
    headB->next->next->next = intersect;

    // Print the lists
    std::cout << "List A: ";
    printList(headA);
    std::cout << "List B: ";
    printList(headB);

    // Find and print the intersection node
    ListNode* intersectionNode = getIntersectionNode(headA, headB);
    if (intersectionNode) {
        std::cout << "Intersection node value: " << intersectionNode->val << std::endl;
    } else {
        std::cout << "No intersection node found." << std::endl;
    }

    // Free allocated memory
    delete intersect->next->next; // Delete node with value 5
    delete intersect->next; // Delete node with value 4
    delete intersect; // Delete node with value 8
    delete headA->next; // Delete node with value 1 in List A
    delete headA; // Delete node with value 4 in List A
    delete headB->next->next; // Delete node with value 1 in List B
    delete headB->next; // Delete node with value 6 in List B
    delete headB; // Delete node with value 5 in List B

    return 0;
}
