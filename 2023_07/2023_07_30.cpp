//#include <iostream>
//
//using namespace std;
//
//// Definition for singly-linked list.
//struct ListNode {
//    int val;
//    ListNode* next;
//    ListNode(int x) : val(x), next(NULL) {}
//};
//
//class Solution {
//public:
//    ListNode* detectCycle(ListNode* head) {
//        ListNode* slow = head;
//        ListNode* fast = head;
//
//        // Step 1: Find the meeting point (if any)
//        while (fast != nullptr && fast->next != nullptr) {
//            slow = slow->next;
//            fast = fast->next->next;
//            if (slow == fast) break; // Found the meeting point
//        }
//
//        // If there is no cycle, return nullptr
//        if (fast == nullptr || fast->next == nullptr) {
//            return nullptr;
//        }
//
//        // Step 2: Find the cycle's entrance
//        slow = head;
//        while (slow != fast) {
//            slow = slow->next;
//            fast = fast->next;
//        }
//
//        return slow; // Return the cycle's entrance
//    }
//};
//
//// Utility function to create a linked list from an array
//ListNode* createLinkedList(int arr[], int n) {
//    if (n == 0) return nullptr;
//    ListNode* head = new ListNode(arr[0]);
//    ListNode* current = head;
//    for (int i = 1; i < n; ++i) {
//        current->next = new ListNode(arr[i]);
//        current = current->next;
//    }
//    return head;
//}
//
//// Utility function to print the linked list
//void printLinkedList(ListNode* head) {
//    ListNode* current = head;
//    while (current != nullptr) {
//        cout << current->val;
//        if (current->next != nullptr) {
//            cout << " -> ";
//        }
//        current = current->next;
//    }
//    cout << endl;
//}
//
//int main() {
//    int arr[] = { 3, 2, 0, -4 };
//    int n = sizeof(arr) / sizeof(arr[0]);
//
//    // Create a circular linked list
//    ListNode* head = createLinkedList(arr, n);
//    ListNode* tail = head;
//    while (tail->next != nullptr) {
//        tail = tail->next;
//    }
//    tail->next = head->next; // Create a cycle
//
//    // Find the cycle's entrance using the Solution class
//    Solution solution;
//    ListNode* entrance = solution.detectCycle(head);
//
//    if (entrance != nullptr) {
//        cout << "Cycle's entrance: " << entrance->val << endl;
//    }
//    else {
//        cout << "No cycle found." << endl;
//    }
//
//    return 0;
//}

#include <iostream>

using namespace std;

// 单链表的定义
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* detectCycle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        // Step 1: 找到相遇点（如果有环的话）
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) break; // 找到相遇点
        }

        // 如果链表中不存在环，返回 nullptr
        if (fast == nullptr || fast->next == nullptr) {
            return nullptr;
        }

        // Step 2: 找到环的入口点
        slow = head;
        while (slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }

        return slow; // 返回环的入口点
    }
};

// 从数组创建链表的工具函数
ListNode* createLinkedList(int arr[], int n) {
    if (n == 0) return nullptr;
    ListNode* head = new ListNode(arr[0]);
    ListNode* current = head;
    for (int i = 1; i < n; ++i) {
        current->next = new ListNode(arr[i]);
        current = current->next;
    }
    return head;
}

// 打印链表的工具函数
void printLinkedList(ListNode* head) {
    ListNode* current = head;
    while (current != nullptr) {
        cout << current->val;
        if (current->next != nullptr) {
            cout << " -> ";
        }
        current = current->next;
    }
    cout << endl;
}

int main() {
    int arr[] = { 3, 2, 0, -4 };
    int n = sizeof(arr) / sizeof(arr[0]);

    // 创建一个带环的链表
    ListNode* head = createLinkedList(arr, n);
    ListNode* tail = head;
    while (tail->next != nullptr) {
        tail = tail->next;
    }
    tail->next = head->next; // 创建一个环

    // 使用 Solution 类来找到环的入口点
    Solution solution;
    ListNode* entrance = solution.detectCycle(head);

    if (entrance != nullptr) {
        cout << "环的入口点: " << entrance->val << endl;
    }
    else {
        cout << "链表中没有环." << endl;
    }

    return 0;
}
