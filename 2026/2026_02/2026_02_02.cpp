#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

/*
 * Container：用两个 multiset 维护“前 k 小值”
 *
 * st1：保存当前集合中最小的 k 个元素
 * st2：保存其余较大的元素
 * sm ：st1 中元素的和
 */
class Container {
public:
    Container(int k) : k(k), sm(0) {}

    /*
     * 调整两个 multiset 的大小关系
     * 保证：
     * 1. st1 中正好存放 k 个最小值（或不足 k 个）
     * 2. st1 中所有元素 <= st2 中任意元素
     */
    void adjust() {
        // st1 不足 k 个，从 st2 中补最小的
        while ((int)st1.size() < k && !st2.empty()) {
            int x = *st2.begin();
            st2.erase(st2.begin());
            st1.insert(x);
            sm += x;
        }
        // st1 超过 k 个，把最大的移到 st2
        while ((int)st1.size() > k) {
            auto it = prev(st1.end());
            int x = *it;
            st1.erase(it);
            st2.insert(x);
            sm -= x;
        }
    }

    // 向集合中插入元素 x
    void add(int x) {
        // 如果 x 比 st2 中最小的还大，直接放 st2
        if (!st2.empty() && x >= *st2.begin()) {
            st2.insert(x);
        }
        else {
            // 否则先放 st1
            st1.insert(x);
            sm += x;
        }
        adjust();
    }

    // 从集合中删除元素 x
    void erase(int x) {
        auto it = st1.find(x);
        if (it != st1.end()) {
            st1.erase(it);
            sm -= x;
        }
        else {
            // 一定存在于 st2
            st2.erase(st2.find(x));
        }
        adjust();
    }

    // 返回当前前 k 小元素之和
    long long sum() const {
        return sm;
    }

private:
    int k;                 // 需要维护的前 k 小值个数
    multiset<int> st1;     // 前 k 小值
    multiset<int> st2;     // 其它值
    long long sm;          // st1 中元素的和
};

class Solution {
public:
    /*
     * minimumCost：
     * 使用滑动窗口 + 两个 multiset 维护窗口中前 k-1 小的起点值
     */
    long long minimumCost(vector<int>& nums, int k, int dist) {
        int n = (int)nums.size();

        // 特殊情况：只需要 1 个子数组
        if (k == 1) return nums[0];

        /*
         * Container 维护的是：
         * 第 2 ~ 第 (k-1) 个子数组起点的最小值
         * 数量为 k-2
         */
        Container cnt(k - 2);

        // 初始化窗口：[1, k-2]
        for (int i = 1; i < k - 1; i++) {
            cnt.add(nums[i]);
        }

        // 初始答案：前 k-1 个子数组起点 + 第 k 个起点
        long long ans = cnt.sum() + nums[k - 1];

        /*
         * i 表示第 k 个子数组的起点
         * 同时维护一个长度不超过 dist 的滑动窗口
         */
        for (int i = k; i < n; i++) {
            int j = i - dist - 1;
            // 窗口左端移出
            if (j > 0) {
                cnt.erase(nums[j]);
            }
            // 加入新的候选起点
            cnt.add(nums[i - 1]);

            // 更新最小代价
            ans = min(ans, cnt.sum() + nums[i]);
        }

        // 加上第一个子数组的起点 nums[0]
        return ans + nums[0];
    }
};

int main() {
    Solution sol;

    // 示例 1
    vector<int> nums1 = { 1, 3, 2, 6, 4, 2 };
    cout << sol.minimumCost(nums1, 3, 3) << endl; // 5

    // 示例 2
    vector<int> nums2 = { 10, 1, 2, 2, 2, 1 };
    cout << sol.minimumCost(nums2, 4, 3) << endl; // 15

    // 示例 3
    vector<int> nums3 = { 10, 8, 18, 9 };
    cout << sol.minimumCost(nums3, 3, 1) << endl; // 36

    return 0;
}
