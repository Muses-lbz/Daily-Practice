#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        unordered_map<int, int> freq;
        int n = (int)basket1.size();
        int global_min = INT_MAX; // 所有水果中最小的成本

        // 统计每个水果在 basket1 和 basket2 中的出现差值
        for (int i = 0; i < n; ++i) {
            freq[basket1[i]]++;
            freq[basket2[i]]--;
            global_min = min({ global_min, basket1[i], basket2[i] });
        }

        vector<int> extra; // 多出来需要交换的水果

        // 检查是否能使两个果篮相等，并收集需要交换的水果
        for (auto& [fruit, count] : freq) {
            // 如果某个水果的总数为奇数，说明无法平分，返回 -1
            if (count % 2 != 0) return -1;
            // 将多出来的一半加入交换列表
            for (int i = 0; i < abs(count) / 2; ++i) {
                extra.push_back(fruit);
            }
        }

        // 对额外水果排序（升序）
        sort(extra.begin(), extra.end());

        long long cost = 0;
        int m = (int)extra.size();

        // 只需前一半的水果与后一半配对交换
        for (int i = 0; i < m / 2; ++i) {
            // 成本为当前水果和两倍最小水果的较小值（可能更划算）
            cost += min(extra[i], 2 * global_min);
        }

        return cost;
    }
};

int main() {
    Solution solution;

    // 示例 1
    vector<int> basket1_1 = { 4, 2, 2, 2 };
    vector<int> basket2_1 = { 1, 4, 1, 2 };
    cout << "示例 1 输出：" << solution.minCost(basket1_1, basket2_1) << endl;

    // 示例 2
    vector<int> basket1_2 = { 2, 3, 4, 1 };
    vector<int> basket2_2 = { 3, 2, 5, 1 };
    cout << "示例 2 输出：" << solution.minCost(basket1_2, basket2_2) << endl;

    return 0;
}
