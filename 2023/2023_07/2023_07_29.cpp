#include <iostream>
#include <unordered_set>

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    bool hasCycle(ListNode* head) {
        if (!head || !head->next)
            return false;

        ListNode* slow = head; // 慢指针
        ListNode* fast = head->next; // 快指针

        while (slow != fast) {
            if (!fast || !fast->next) {
                // 如果快指针或者快指针的下一个节点为 NULL，说明链表没有环
                return false;
            }
            slow = slow->next; // 慢指针前进一步
            fast = fast->next->next; // 快指针前进两步
        }

        // 如果能跳出循环，则说明链表有环
        return true;
    }
};

int main() {
    // 创建链表示例，并测试是否有环
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = head->next; // 构造一个有环的链表

    Solution solution;
    if (solution.hasCycle(head)) {
        std::cout << "链表中存在环。" << std::endl;
    }
    else {
        std::cout << "链表中不存在环。" << std::endl;
    }

    return 0;
}
