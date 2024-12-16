#include <iostream>
#include <vector>
#include <algorithm>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

//Link: https://leetcode.com/problems/sort-list/description/

ListNode* sortList(ListNode* head) {
    ListNode* ptr = head;
    std::vector<int> st;
    
    // Store the values into the vector
    while (ptr != NULL) {
        st.push_back(ptr->val);
        ptr = ptr->next;
    }
    
    // Sort the vector
    std::sort(st.begin(), st.end());
    
    // Reassign the sorted values to the linked list
    ptr = head;
    int k = 0;
    while (ptr != NULL) {
        ptr->val = st[k++];
        ptr = ptr->next;
    }
    
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
    // Create a linked list: 4 -> 2 -> 1 -> 3
    ListNode* head = new ListNode(4);
    head->next = new ListNode(2);
    head->next->next = new ListNode(1);
    head->next->next->next = new ListNode(3);

    // Print the original list
    std::cout << "Original list: ";
    printList(head);

    // Sort the list
    head = sortList(head);

    // Print the sorted list
    std::cout << "Sorted list: ";
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

