#include <iostream>
#include <unordered_map>
#include <set>
using namespace std;

// 自定义结构表示缓存条目
struct Node {
    int cnt, time, key, value;

    Node(int _cnt, int _time, int _key, int _value) : cnt(_cnt), time(_time), key(_key), value(_value) {}

    // 自定义比较函数用于set中的排序
    bool operator < (const Node& rhs) const {
        return cnt == rhs.cnt ? time < rhs.time : cnt < rhs.cnt;
    }
};

class LFUCache {
    int capacity, time;
    unordered_map<int, Node> key_table; // 存储缓存的键值对
    set<Node> S; // 维护缓存的顺序
public:
    LFUCache(int _capacity) {
        capacity = _capacity;
        time = 0;
        key_table.clear();
        S.clear();
    }

    int get(int key) {
        if (capacity == 0) return -1;
        auto it = key_table.find(key);
        if (it == key_table.end()) return -1;
        Node cache = it->second;
        S.erase(cache); // 从set中删除旧缓存
        cache.cnt += 1; // 更新缓存的使用计数
        cache.time = ++time;
        S.insert(cache); // 将新缓存重新插入set中
        it->second = cache; // 更新哈希表中的缓存
        return cache.value;
    }

    void put(int key, int value) {
        if (capacity == 0) return;
        auto it = key_table.find(key);
        if (it == key_table.end()) {
            if (key_table.size() == capacity) {
                key_table.erase(S.begin()->key); // 删除最不常用的缓存
                S.erase(S.begin());
            }
            Node cache = Node(1, ++time, key, value); // 创建新缓存
            key_table.insert(make_pair(key, cache)); // 插入新缓存到哈希表
            S.insert(cache); // 插入新缓存到set中
        }
        else {
            Node cache = it->second;
            S.erase(cache); // 从set中删除旧缓存
            cache.cnt += 1; // 更新缓存的使用计数
            cache.time = ++time;
            cache.value = value; // 更新缓存的值
            S.insert(cache); // 将新缓存重新插入set中
            it->second = cache; // 更新哈希表中的缓存
        }
    }
};

int main() {
    LFUCache lfu(2);
    lfu.put(1, 1);
    lfu.put(2, 2);
    cout << lfu.get(1) << endl; // 返回 1
    lfu.put(3, 3); // 去除键 2
    cout << lfu.get(2) << endl; // 返回 -1
    cout << lfu.get(3) << endl; // 返回 3
    lfu.put(4, 4); // 去除键 1
    cout << lfu.get(1) << endl; // 返回 -1
    cout << lfu.get(3) << endl; // 返回 3
    cout << lfu.get(4) << endl; // 返回 4

    return 0;
}
