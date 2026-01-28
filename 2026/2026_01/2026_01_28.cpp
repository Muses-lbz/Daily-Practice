#include <iostream>     // cout, endl
#include <vector>       // vector
#include <algorithm>    // sort, min
#include <climits>      // INT_MAX
#include <utility>      // pair

using namespace std;

class Solution {
public:
    /*
        minCost 函数说明（中文注释）：

        grid[i][j] 表示进入该单元格的代价
        起点为 (0,0)，终点为 (m-1,n-1)

        移动方式：
        1. 普通移动：向右 / 向下，代价为目标格子的值
        2. 传送：最多 k 次，可从 (i,j) 传送到任意
           grid[x][y] <= grid[i][j] 的格子，代价为 0

        核心思想：
        dp[t][i][j] = 在最多使用 t 次传送的情况下，
                      从 (i,j) 到终点的最小代价

        实现时只保留两层：
        prev：t-1 次传送
        cur ：t 次传送
    */
    int minCost(vector<vector<int>>& grid, int k) {
        int m = (int)grid.size();
        int n = (int)grid[0].size();

        // 将所有格子按 grid 值从小到大排序
        vector<pair<int, int>> points;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                points.push_back({ i, j });
            }
        }

        sort(points.begin(), points.end(),
            [&](const pair<int, int>& a, const pair<int, int>& b) {
                return grid[a.first][a.second] <
                    grid[b.first][b.second];
            });

        // ---------- 0 次传送：只允许普通移动 ----------
        vector<vector<int>> prev(m, vector<int>(n, INT_MAX));
        prev[m - 1][n - 1] = 0;

        // 反向 DP（只能向右或向下）
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (i + 1 < m) {
                    prev[i][j] = min(prev[i][j],
                        prev[i + 1][j] + grid[i + 1][j]);
                }
                if (j + 1 < n) {
                    prev[i][j] = min(prev[i][j],
                        prev[i][j + 1] + grid[i][j + 1]);
                }
            }
        }

        // ---------- 每一轮多允许一次传送 ----------
        for (int t = 1; t <= k; t++) {
            vector<vector<int>> cur = prev;

            // 传送松弛
            int best = INT_MAX;
            for (int i = 0, j = 0; i < (int)points.size(); i++) {
                int x = points[i].first;
                int y = points[i].second;

                best = min(best, prev[x][y]);

                // 相同 grid 值的格子要一起处理
                if (i + 1 < (int)points.size() &&
                    grid[x][y] ==
                    grid[points[i + 1].first][points[i + 1].second]) {
                    continue;
                }

                for (int r = j; r <= i; r++) {
                    int px = points[r].first;
                    int py = points[r].second;
                    cur[px][py] = min(cur[px][py], best);
                }
                j = i + 1;
            }

            // 普通移动 DP
            for (int i = m - 1; i >= 0; i--) {
                for (int j = n - 1; j >= 0; j--) {
                    if (i + 1 < m) {
                        cur[i][j] = min(cur[i][j],
                            cur[i + 1][j] + grid[i + 1][j]);
                    }
                    if (j + 1 < n) {
                        cur[i][j] = min(cur[i][j],
                            cur[i][j + 1] + grid[i][j + 1]);
                    }
                }
            }

            prev.swap(cur);
        }

        return prev[0][0];
    }
};

int main() {
    Solution sol;

    // 示例 1
    vector<vector<int>> grid1 = {
        {1, 3, 3},
        {2, 5, 4},
        {4, 3, 5}
    };
    int k1 = 2;
    cout << "示例 1 输出: " << sol.minCost(grid1, k1) << endl;
    // 期望输出：7

    // 示例 2
    vector<vector<int>> grid2 = {
        {1, 2},
        {2, 3},
        {3, 4}
    };
    int k2 = 1;
    cout << "示例 2 输出: " << sol.minCost(grid2, k2) << endl;
    // 期望输出：9

    return 0;
}
