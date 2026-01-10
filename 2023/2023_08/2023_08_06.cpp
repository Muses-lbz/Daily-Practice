//#include <iostream>
//
//// Definition for singly-linked list.
//struct ListNode {
//    int val;
//    ListNode* next;
//    ListNode() : val(0), next(nullptr) {}
//    ListNode(int x) : val(x), next(nullptr) {}
//    ListNode(int x, ListNode* next) : val(x), next(next) {}
//};
//
//class Solution {
//public:
//    ListNode* swapPairs(ListNode* head) {
//        if (head == nullptr || head->next == nullptr) {
//            return head;
//        }
//
//        ListNode* newHead = head->next;
//        ListNode* prev = nullptr;
//
//        while (head != nullptr && head->next != nullptr) {
//            ListNode* firstNode = head;
//            ListNode* secondNode = head->next;
//
//            firstNode->next = secondNode->next;
//            secondNode->next = firstNode;
//
//            if (prev != nullptr) {
//                prev->next = secondNode;
//            }
//
//            prev = firstNode;
//            head = firstNode->next;
//        }
//
//        return newHead;
//    }
//};
//
//// Helper function to create a linked list
//ListNode* createLinkedList(int arr[], int n) {
//    if (n == 0) {
//        return nullptr;
//    }
//
//    ListNode* head = new ListNode(arr[0]);
//    ListNode* current = head;
//
//    for (int i = 1; i < n; ++i) {
//        current->next = new ListNode(arr[i]);
//        current = current->next;
//    }
//
//    return head;
//}
//
//// Helper function to print a linked list
//void printLinkedList(ListNode* head) {
//    ListNode* current = head;
//    while (current != nullptr) {
//        std::cout << current->val << " ";
//        current = current->next;
//    }
//    std::cout << std::endl;
//}
//
//int main() {
//    int arr[] = { 1, 2, 3, 4, 5 };
//    int n = sizeof(arr) / sizeof(arr[0]);
//
//    ListNode* head = createLinkedList(arr, n);
//
//    Solution solution;
//    ListNode* newHead = solution.swapPairs(head);
//
//    std::cout << "Original Linked List: ";
//    printLinkedList(head);
//
//    std::cout << "Swapped Linked List: ";
//    printLinkedList(newHead);
//
//    return 0;
//}

//#include <iostream>
//
//// Definition for singly-linked list.
//struct ListNode {
//    int val;
//    ListNode* next;
//    ListNode() : val(0), next(nullptr) {}
//    ListNode(int x) : val(x), next(nullptr) {}
//    ListNode(int x, ListNode* next) : val(x), next(next) {}
//};
//
//class Solution {
//public:
//    ListNode* swapPairs(ListNode* head) {
//        // 如果链表为空或只有一个节点，直接返回原链表头
//        if (head == nullptr || head->next == nullptr) {
//            return head;
//        }
//
//        // 新链表的头节点是原链表的第二个节点
//        ListNode* newHead = head->next;
//
//        // 当前节点的前一个节点，用于连接交换后的节点
//        ListNode* prev = nullptr;
//
//        // 逐对交换相邻的节点
//        while (head != nullptr && head->next != nullptr) {
//            ListNode* firstNode = head;         // 第一个节点
//            ListNode* secondNode = head->next;  // 第二个节点
//
//            // 进行交换
//            firstNode->next = secondNode->next;
//            secondNode->next = firstNode;
//
//            // 连接交换后的节点到前一个节点
//            if (prev != nullptr) {
//                prev->next = secondNode;
//            }
//
//            prev = firstNode;  // 更新前一个节点为第一个节点
//            head = firstNode->next;  // 更新头节点为下一组的第一个节点
//        }
//
//        return newHead;
//    }
//};
//
//// Helper function to create a linked list
//ListNode* createLinkedList(int arr[], int n) {
//    if (n == 0) {
//        return nullptr;
//    }
//
//    ListNode* head = new ListNode(arr[0]);
//    ListNode* current = head;
//
//    for (int i = 1; i < n; ++i) {
//        current->next = new ListNode(arr[i]);
//        current = current->next;
//    }
//
//    return head;
//}
//
//// Helper function to print a linked list
//void printLinkedList(ListNode* head) {
//    ListNode* current = head;
//    while (current != nullptr) {
//        std::cout << current->val << " ";
//        current = current->next;
//    }
//    std::cout << std::endl;
//}
//
//int main() {
//    int arr[] = { 1, 2, 3, 4, 5 };
//    int n = sizeof(arr) / sizeof(arr[0]);
//
//    ListNode* head = createLinkedList(arr, n);
//
//    Solution solution;
//    ListNode* newHead = solution.swapPairs(head);
//
//    std::cout << "Original Linked List: ";
//    printLinkedList(head);
//
//    std::cout << "Swapped Linked List: ";
//    printLinkedList(newHead);
//
//    return 0;
//}

//#include <iostream>
//#include <vector>
//
//class Solution {
//public:
//    int climbStairs(int n) {
//        if (n <= 2) {
//            return n;
//        }
//
//        std::vector<int> dp(n + 1);
//        dp[1] = 1;
//        dp[2] = 2;
//
//        for (int i = 3; i <= n; ++i) {
//            dp[i] = dp[i - 1] + dp[i - 2];
//        }
//
//        return dp[n];
//    }
//};
//
//int main() {
//    Solution solution;
//    int n = 3; // 你可以修改n的值来测试不同的阶数
//    int ways = solution.climbStairs(n);
//
//    std::cout << "Number of ways to climb " << n << " stairs: " << ways << std::endl;
//
//    system("pause");
//
//    return 0;
//}

#include <iostream>
#include <vector>

class Solution {
public:
    int climbStairs(int n) {
        // 如果楼梯阶数小于等于2，直接返回阶数，因为对于1阶和2阶楼梯，方法数分别为1和2
        if (n <= 2) {
            return n;
        }

        // 创建一个动态规划数组，用于存储每一阶楼梯的方法数
        std::vector<int> dp(n + 1);

        // 初始情况：1阶楼梯有1种方法，2阶楼梯有2种方法
        dp[1] = 1;
        dp[2] = 2;

        // 计算每一阶楼梯的方法数，利用前两阶的方法数之和
        for (int i = 3; i <= n; ++i) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }

        // 返回到达第n阶楼梯的方法数
        return dp[n];
    }
};

int main() {
    Solution solution;
    int n = 3; // 你可以修改n的值来测试不同的阶数
    int ways = solution.climbStairs(n);

    std::cout << "Number of ways to climb " << n << " stairs: " << ways << std::endl;

    // 在Windows下暂停程序以查看输出结果（system("pause")在其他平台上可能无效）
    system("pause");

    return 0;
}
