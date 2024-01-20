// Merge two lists into one sorted list. The list should be made by splicing together the nodes of the first two lists.

#include <iostream>

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

void printList(ListNode* head) {
    while (head != nullptr) {
        std::cout << head->val << " ";
        head = head->next;
    }
    std::cout << std::endl;
}


    // Merge and sort the input lists
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    ListNode dummy(0);  // Dummy node to simplify code
    ListNode* current = &dummy;

    while (l1 != nullptr && l2 != nullptr) {
        if (l1->val < l2->val) {
            current->next = l1;
            l1 = l1->next;
        } else {
            current->next = l2;
            l2 = l2->next;
        }
        current = current->next;
    }

    // Link the remaining nodes from the non-empty list
    current->next = (l1 != nullptr) ? l1 : l2;

    // Sort the merged list
    ListNode* sortedList = dummy.next;
    dummy.next = nullptr;

    while (sortedList != nullptr) {
        ListNode* temp = sortedList;
        sortedList = sortedList->next;

        // Insert the node in sorted order
        ListNode* insertPos = &dummy;
        while (insertPos->next != nullptr && insertPos->next->val < temp->val) {
            insertPos = insertPos->next;
        }

        temp->next = insertPos->next;
        insertPos->next = temp;
    }

    return dummy.next;  // The merged and sorted list starts from the next of the dummy node
}





int main() {
    ListNode* list1 = new ListNode(3);
    list1->next = new ListNode(1);
    list1->next->next = new ListNode(4);

    ListNode* list2 = new ListNode(2);
    list2->next = new ListNode(6);
    list2->next->next = new ListNode(5);

    ListNode* mergedList = mergeTwoLists(list1, list2);

    std::cout << "Merged List: ";
    printList(mergedList);

    // Clean up the memory
    while (mergedList) {
        ListNode* temp = mergedList;
        mergedList = mergedList->next;
        delete temp;
    }

    return 0;
}
