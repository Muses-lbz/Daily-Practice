#include <vector>
#include <algorithm>
#include <iostream>
#include <climits>

using namespace std;

class Solution {
public:
    int paintWalls(vector<int>& cost, vector<int>& time) {
        int n = (int)cost.size();
        // 创建动态规划数组，大小为2n+1，初始化为INT_MAX / 2
        vector<int> f(n * 2 + 1, INT_MAX / 2);
        f[n] = 0;  // 初始化中间状态为0

        for (int i = 0; i < n; ++i) {
            // 临时数组g，用于存储当前墙的计算结果
            vector<int> g(n * 2 + 1, INT_MAX / 2);

            for (int j = 0; j <= n * 2; ++j) {
                // 选择付费油漆匠刷当前墙，时间增加time[i]，花费增加cost[i]
                g[min(j + time[i], n * 2)] = min(g[min(j + time[i], n * 2)], f[j] + cost[i]);

                // 选择免费油漆匠刷当前墙，时间减少1，花费不变
                if (j > 0) {
                    g[j - 1] = min(g[j - 1], f[j]);
                }
            }

            // 更新动态规划数组
            f = move(g);
        }

        // 从f数组中找到最小的开销值
        return *min_element(f.begin() + n, f.end());
    }
};

int main() {
    Solution solution;

    vector<int> cost1 = { 1, 2, 3, 2 };
    vector<int> time1 = { 1, 2, 3, 2 };
    cout << "输出: " << solution.paintWalls(cost1, time1) << endl; // 输出: 3

    vector<int> cost2 = { 2, 3, 4, 2 };
    vector<int> time2 = { 1, 1, 1, 1 };
    cout << "输出: " << solution.paintWalls(cost2, time2) << endl; // 输出: 4

    return 0;
}
