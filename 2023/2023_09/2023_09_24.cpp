#include <iostream>
#include <unordered_map>
using namespace std;

class LRUCache {
public:
    struct ListNode {
        int key;
        int value;
        ListNode* prev;
        ListNode* next;
        ListNode(int k, int v) : key(k), value(v), prev(nullptr), next(nullptr) {}
    };

    LRUCache(int capacity) {
        capacity_ = capacity;
        head_ = new ListNode(-1, -1);
        tail_ = new ListNode(-1, -1);
        head_->next = tail_;
        tail_->prev = head_;
    }

    int get(int key) {
        if (cache_.find(key) != cache_.end()) {
            // 移动访问的节点到链表头部
            ListNode* node = cache_[key];
            moveToHead(node);
            return node->value;
        }
        return -1;
    }

    void put(int key, int value) {
        if (cache_.find(key) != cache_.end()) {
            // 更新已存在的节点的值，并移动到链表头部
            ListNode* node = cache_[key];
            node->value = value;
            moveToHead(node);
        }
        else {
            if (cache_.size() >= capacity_) {
                // 移除链表尾部的节点（最久未使用的）
                ListNode* tailNode = tail_->prev;
                removeFromList(tailNode);
                cache_.erase(tailNode->key);
                delete tailNode;
            }
            // 创建新节点，并添加到链表头部
            ListNode* newNode = new ListNode(key, value);
            addToFront(newNode);
            cache_[key] = newNode;
        }
    }

    ~LRUCache() {
        // 释放链表和哈希表的内存
        ListNode* node = head_->next;
        while (node != tail_) {
            ListNode* temp = node;
            node = node->next;
            delete temp;
        }
        delete head_;
        delete tail_;
    }

private:
    int capacity_;
    unordered_map<int, ListNode*> cache_;
    ListNode* head_;
    ListNode* tail_;

    void moveToHead(ListNode* node) {
        // 从链表中移除节点
        removeFromList(node);
        // 添加到链表头部
        addToFront(node);
    }

    void removeFromList(ListNode* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void addToFront(ListNode* node) {
        node->next = head_->next;
        head_->next->prev = node;
        head_->next = node;
        node->prev = head_;
    }
};

int main() {
    LRUCache lRUCache(2);
    lRUCache.put(1, 1);
    lRUCache.put(2, 2);
    cout << lRUCache.get(1) << endl; // 返回 1
    lRUCache.put(3, 3); // 移除键 2
    cout << lRUCache.get(2) << endl; // 返回 -1
    lRUCache.put(4, 4); // 移除键 1
    cout << lRUCache.get(1) << endl; // 返回 -1
    cout << lRUCache.get(3) << endl; // 返回 3
    cout << lRUCache.get(4) << endl; // 返回 4

    return 0;
}
