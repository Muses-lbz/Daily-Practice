#include <iostream>
#include <vector>
#include <set>
#include <climits>

using namespace std;

class Solution {
public:
    // 计算移除一个点后，其余点之间的最大曼哈顿距离的最小值
    int minimumDistance(vector<vector<int>>& points) {
        multiset<int> sx, sy; // 用 multiset 维护变换后的坐标
        for (auto& p : points) {
            // 将变换后的坐标加入 multiset
            sx.emplace(p[0] - p[1]);
            sy.emplace(p[0] + p[1]);
        }

        int res = INT_MAX; // 初始化结果为最大整数值

        for (auto& p : points) {
            // 从 multiset 中移除当前点的变换后的坐标
            sx.erase(sx.find(p[0] - p[1]));
            sy.erase(sy.find(p[0] + p[1]));

            // 计算当前 multiset 中的最大值和最小值之差，并更新结果
            res = min(res, max(*sx.rbegin() - *sx.begin(), *sy.rbegin() - *sy.begin()));

            // 将当前点的变换后的坐标重新加入到 multiset 中
            sx.emplace(p[0] - p[1]);
            sy.emplace(p[0] + p[1]);
        }

        return res; // 返回最终结果
    }
};

// 主函数，用于测试
int main() {
    Solution sol;

    // 示例1
    vector<vector<int>> points1 = { {3, 10}, {5, 15}, {10, 2}, {4, 4} };
    int result1 = sol.minimumDistance(points1);
    printf("示例1的结果: %d\n", result1); // 输出: 12

    // 示例2（可添加更多示例进行测试）
    vector<vector<int>> points2 = { {1, 2}, {2, 3}, {3, 4}, {4, 5} };
    int result2 = sol.minimumDistance(points2);
    printf("示例2的结果: %2d\n", result2); // 输出: 3

    return 0;
}
