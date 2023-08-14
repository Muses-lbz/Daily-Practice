//#include <iostream>
//#include <vector>
//#include <queue>
//
//using namespace std;
//
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
//    struct Compare {
//        bool operator()(const ListNode* a, const ListNode* b) {
//            return a->val > b->val;
//        }
//    };
//
//    ListNode* mergeKLists(vector<ListNode*>& lists) {
//        priority_queue<ListNode*, vector<ListNode*>, Compare> pq; // 最小堆
//
//        for (ListNode* list : lists) {
//            if (list)
//                pq.push(list);
//        }
//
//        ListNode dummy; // 虚拟头结点
//        ListNode* current = &dummy;
//
//        while (!pq.empty()) {
//            ListNode* smallest = pq.top();
//            pq.pop();
//
//            current->next = smallest;
//            current = current->next;
//
//            if (smallest->next)
//                pq.push(smallest->next);
//        }
//
//        return dummy.next;
//    }
//};
//
//int main() {
//    Solution solution;
//
//    // Create example linked lists
//    ListNode* list1 = new ListNode(1);
//    list1->next = new ListNode(4);
//    list1->next->next = new ListNode(5);
//
//    ListNode* list2 = new ListNode(1);
//    list2->next = new ListNode(3);
//    list2->next->next = new ListNode(4);
//
//    ListNode* list3 = new ListNode(2);
//    list3->next = new ListNode(6);
//
//    vector<ListNode*> lists = { list1, list2, list3 };
//
//    // Merge the lists
//    ListNode* mergedList = solution.mergeKLists(lists);
//
//    // Print the merged list
//    while (mergedList) {
//        cout << mergedList->val << " ";
//        mergedList = mergedList->next;
//    }
//
//    return 0;
//}

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    // 自定义比较函数，用于优先队列的最小堆
    struct Compare {
        bool operator()(const ListNode* a, const ListNode* b) {
            return a->val > b->val; // 较小的值优先级高
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // 创建一个优先队列（最小堆），用于保存链表的头节点
        priority_queue<ListNode*, vector<ListNode*>, Compare> pq;

        // 将所有非空链表的头节点放入优先队列中
        for (ListNode* list : lists) {
            if (list)
                pq.push(list);
        }

        ListNode dummy; // 创建虚拟头结点
        ListNode* current = &dummy; // 创建当前节点指针，用于构建合并后的链表

        // 当优先队列不为空时，不断从最小堆中取出最小节点，将其接入合并后的链表，并将下一个节点（如果有的话）放入优先队列
        while (!pq.empty()) {
            ListNode* smallest = pq.top(); // 取出最小节点
            pq.pop(); // 弹出最小节点

            current->next = smallest; // 将最小节点接入合并后的链表
            current = current->next; // 更新当前节点指针

            if (smallest->next)
                pq.push(smallest->next); // 将下一个节点放入优先队列
        }

        return dummy.next; // 返回合并后的链表
    }
};

int main() {
    Solution solution;

    // 创建示例链表
    ListNode* list1 = new ListNode(1);
    list1->next = new ListNode(4);
    list1->next->next = new ListNode(5);

    ListNode* list2 = new ListNode(1);
    list2->next = new ListNode(3);
    list2->next->next = new ListNode(4);

    ListNode* list3 = new ListNode(2);
    list3->next = new ListNode(6);

    vector<ListNode*> lists = { list1, list2, list3 }; // 创建链表数组

    // 合并链表
    ListNode* mergedList = solution.mergeKLists(lists);

    // 打印合并后的链表
    while (mergedList) {
        cout << mergedList->val << " ";
        mergedList = mergedList->next;
    }

    //谨记释放内存，但是代码有问题，无法编写出来

    return 0;
}
