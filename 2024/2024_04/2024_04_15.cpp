#include <iostream>
#include <vector>
#include <list>
#include <utility> // for std::pair

using namespace std;

class MyHashMap {
private:
    vector<list<pair<int, int>>> data; // 使用 vector 存储链表，实现哈希桶
    static const int base = 769; // 选择一个素数作为哈希基数
    static int hash(int key) { // 哈希函数
        return key % base;
    }
public:
    /** 初始化哈希映射数据结构 */
    MyHashMap() : data(base) {}

    /** 向哈希映射中插入键值对，若键已存在，则更新其对应的值 */
    void put(int key, int value) {
        int h = hash(key); // 计算哈希值
        for (auto it = data[h].begin(); it != data[h].end(); it++) { // 遍历链表
            if ((*it).first == key) { // 若键已存在，则更新值
                (*it).second = value;
                return;
            }
        }
        data[h].push_back(make_pair(key, value)); // 否则插入新的键值对
    }

    /** 返回指定键的映射值，若哈希映射中不包含该键，则返回 -1 */
    int get(int key) {
        int h = hash(key); // 计算哈希值
        for (auto it = data[h].begin(); it != data[h].end(); it++) { // 遍历链表
            if ((*it).first == key) { // 若找到键，则返回对应值
                return (*it).second;
            }
        }
        return -1; // 否则返回 -1
    }

    /** 若哈希映射中存在指定键的映射，则删除该键值对 */
    void remove(int key) {
        int h = hash(key); // 计算哈希值
        for (auto it = data[h].begin(); it != data[h].end(); it++) { // 遍历链表
            if ((*it).first == key) { // 若找到键，则删除对应键值对
                data[h].erase(it);
                return;
            }
        }
    }
};

int main() {
    MyHashMap myHashMap; // 创建 MyHashMap 实例

    // 使用示例
    myHashMap.put(1, 1); // 插入键值对 [1, 1]
    myHashMap.put(2, 2); // 插入键值对 [2, 2]
    cout << myHashMap.get(1) << endl; // 获取键 1 对应的值，输出 1
    cout << myHashMap.get(3) << endl; // 获取键 3 对应的值，输出 -1（未找到）
    myHashMap.put(2, 1); // 更新键为 2 的值为 1
    cout << myHashMap.get(2) << endl; // 获取键 2 对应的值，输出 1
    myHashMap.remove(2); // 删除键为 2 的键值对
    cout << myHashMap.get(2) << endl; // 获取键 2 对应的值，输出 -1（未找到）

    return 0;
}
