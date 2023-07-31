#include <iostream>

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    void reorderList(ListNode* head) {
        if (!head || !head->next)
            return;

        // Find the middle of the list
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Split the list into two parts
        ListNode* secondHalf = slow->next;
        slow->next = nullptr;

        // Reverse the second half of the list
        ListNode* prev = nullptr;
        ListNode* current = secondHalf;
        while (current) {
            ListNode* temp = current->next;
            current->next = prev;
            prev = current;
            current = temp;
        }

        // Merge the two lists
        ListNode* firstHalf = head;
        while (firstHalf && prev) {
            ListNode* firstTemp = firstHalf->next;
            ListNode* secondTemp = prev->next;

            firstHalf->next = prev;
            prev->next = firstTemp;

            firstHalf = firstTemp;
            prev = secondTemp;
        }
    }
};

// Function to insert a node at the end of the linked list
void insert(ListNode*& head, int val) {
    ListNode* newNode = new ListNode(val);
    if (!head) {
        head = newNode;
    }
    else {
        ListNode* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Function to print the linked list
void printList(ListNode* head) {
    ListNode* current = head;
    while (current) {
        std::cout << current->val << " -> ";
        current = current->next;
    }
    std::cout << "nullptr" << std::endl;
}

int main() {
    ListNode* head = nullptr;

    // Create a linked list: 1 -> 2 -> 3 -> 4 -> 5 -> nullptr
    insert(head, 1);
    insert(head, 2);
    insert(head, 3);
    insert(head, 4);
    insert(head, 5);

    std::cout << "Original Linked List: ";
    printList(head);

    Solution solution;
    solution.reorderList(head);

    std::cout << "Reordered Linked List: ";
    printList(head);

    // Clean up the memory (optional)
    ListNode* current = head;
    while (current) {
        ListNode* temp = current;
        current = current->next;
        delete temp;
    }

    return 0;
}
