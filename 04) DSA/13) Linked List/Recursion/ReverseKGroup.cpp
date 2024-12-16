#include <iostream>

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};
//Link:https://leetcode.com/problems/reverse-nodes-in-k-group/description/
ListNode* reverseKGroup(ListNode* head, int k) {
    if (head == NULL) {
        return head;
    }

    int cnt = 0;
    ListNode* curr = head;
    ListNode* prev = NULL;
    ListNode* nextptr = NULL;

    // Check for at least k nodes remaining
    ListNode* temp = head;
    for (int i = 0; i < k; i++) {
        if (temp == NULL) {
            return head;
        }
        temp = temp->next;
    }

    // Reversing part
    while (curr != NULL && cnt < k) {
        nextptr = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextptr;
        cnt++;
    }

    if (nextptr != NULL) {
        head->next = reverseKGroup(nextptr, k);
    }

    return prev;
}
ListNode* createList(std::initializer_list<int> values) {
    ListNode* head = NULL;
    ListNode* tail = NULL;
    for (int value : values) {
        ListNode* newNode = new ListNode(value);
        if (!head) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    return head;
}

void printList(ListNode* head) {
    ListNode* temp = head;
    while (temp) {
        std::cout << temp->val;
        if (temp->next) {
            std::cout << " -> ";
        }
        temp = temp->next;
    }
    std::cout << std::endl;
}

int main() {
    // Create a sample list: 1 -> 2 -> 3 -> 4 -> 5
    ListNode* head = createList({1, 2, 3, 4, 5});
    int k = 3;

    std::cout << "Original list: ";
    printList(head);

    // Reverse nodes in k-group
    ListNode* newHead = reverseKGroup(head, k);

    std::cout << "Reversed list in k-group: ";
    printList(newHead);

    return 0;
}

