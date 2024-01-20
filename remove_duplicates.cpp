//Given the head of a sorted linked list, delete all duplicates such that each element appears only once. Return the linked list sorted as well.

#include <iostream>

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Function to print the linked list
void printList(ListNode* head) {
    while (head != nullptr) {
        std::cout << head->val << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

// Function to delete duplicates from a sorted linked list
ListNode* deleteDuplicates(ListNode* head) {
    ListNode* current = head;

    while (current != nullptr && current->next != nullptr) {
        if (current->val == current->next->val) {
            // Duplicate found, remove the next node
            ListNode* temp = current->next;
            current->next = current->next->next;
            delete temp;
        } else {
            // Move to the next node
            current = current->next;
        }
    }

    return head;
}

int main() {
    // Example sorted linked list: 1 -> 1 -> 2 -> 3 -> 3
    ListNode* head = new ListNode(4);
    head->next = new ListNode(6);
    head->next->next = new ListNode(6);
    head->next->next->next = new ListNode(9);
    head->next->next->next->next = new ListNode(9);

    std::cout << "Original List: ";
    printList(head);

    // Delete duplicates
    head = deleteDuplicates(head);

    std::cout << "List after deleting duplicates: ";
    printList(head);

    // Clean up the memory
    while (head != nullptr) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
