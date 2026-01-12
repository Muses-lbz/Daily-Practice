#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    // 计算访问所有点的最小时间
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int ans = 0;

        // 从第 2 个点开始，依次计算相邻两点的最短时间
        for (int i = 1; i < points.size(); i++) {
            // x 方向的距离
            int dx = abs(points[i][0] - points[i - 1][0]);
            // y 方向的距离
            int dy = abs(points[i][1] - points[i - 1][1]);

            // 由于可以走对角线，最短时间是 max(dx, dy)
            ans += max(dx, dy);
        }

        return ans;
    }
};

int main() {
    Solution solution;

    // 示例 1
    vector<vector<int>> points1 = {
        {1, 1},
        {3, 4},
        {-1, 0}
    };

    // 调用函数并输出结果
    cout << "示例 1 的最小时间: "
        << solution.minTimeToVisitAllPoints(points1) << endl;
    // 期望输出：7

    // 示例 2
    vector<vector<int>> points2 = {
        {3, 2},
        {-2, 2}
    };

    cout << "示例 2 的最小时间: "
        << solution.minTimeToVisitAllPoints(points2) << endl;
    // 期望输出：5

    return 0;
}
