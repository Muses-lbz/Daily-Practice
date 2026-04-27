#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/*
题目：判断网格中是否存在一条从左上角到右下角的有效路径
核心思想：BFS + 连通性判断（双向匹配）
*/

class Solution {
public:
    bool hasValidPath(vector<vector<int>>& grid) {
        int m = grid.size();        // 行数
        int n = grid[0].size();     // 列数

        // 四个方向：上、右、下、左（按顺序编号 0,1,2,3）
        vector<pair<int, int>> dirs = {
            {-1, 0},  // 上
            {0, 1},   // 右
            {1, 0},   // 下
            {0, -1}   // 左
        };

        // 每种街道类型允许走的方向
        // type_dirs[i] 表示类型 i 可以走的方向编号
        vector<vector<int>> type_dirs = {
            {},             // 0 占位（不用）
            {3, 1},         // 1：左 ↔ 右
            {0, 2},         // 2：上 ↕ 下
            {3, 2},         // 3：左 ↔ 下
            {1, 2},         // 4：右 ↔ 下
            {3, 0},         // 5：左 ↔ 上
            {1, 0}          // 6：右 ↔ 上
        };

        // 方向的反向（用于判断能否“接回来”）
        // 例如：上(0) 的反方向是 下(2)
        int opposite[4] = { 2, 3, 0, 1 };

        // BFS 队列
        queue<pair<int, int>> q;

        // 访问标记数组
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        // 从起点开始
        q.push({ 0, 0 });
        visited[0][0] = true;

        // BFS 遍历
        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            // 如果到达终点，返回 true
            if (x == m - 1 && y == n - 1) {
                return true;
            }

            int type = grid[x][y];  // 当前格子的街道类型

            // 遍历当前格子允许的所有方向
            for (int d : type_dirs[type]) {
                int nx = x + dirs[d].first;
                int ny = y + dirs[d].second;

                // 越界判断
                if (nx < 0 || ny < 0 || nx >= m || ny >= n)
                    continue;

                // 已访问过则跳过
                if (visited[nx][ny])
                    continue;

                int next_type = grid[nx][ny];  // 下一个格子的类型

                // 判断：下一个格子是否能“反向连接回来”
                for (int nd : type_dirs[next_type]) {
                    if (nd == opposite[d]) {
                        // 可以连通
                        visited[nx][ny] = true;
                        q.push({ nx, ny });
                        break;
                    }
                }
            }
        }

        // BFS 结束仍未到达终点
        return false;
    }
};


int main() {
    Solution sol;

    // 测试样例 1
    vector<vector<int>> grid1 = {
        {2, 4, 3},
        {6, 5, 2}
    };

    cout << "示例1结果: " << (sol.hasValidPath(grid1) ? "true" : "false") << endl;

    // 测试样例 2
    vector<vector<int>> grid2 = {
        {1, 2, 1},
        {1, 2, 1}
    };

    cout << "示例2结果: " << (sol.hasValidPath(grid2) ? "true" : "false") << endl;

    // 测试样例 3
    vector<vector<int>> grid3 = {
        {1, 1, 2}
    };

    cout << "示例3结果: " << (sol.hasValidPath(grid3) ? "true" : "false") << endl;

    // 测试样例 4
    vector<vector<int>> grid4 = {
        {1,1,1,1,1,1,3}
    };

    cout << "示例4结果: " << (sol.hasValidPath(grid4) ? "true" : "false") << endl;

    // 测试样例 5
    vector<vector<int>> grid5 = {
        {2},{2},{2},{2},{2},{2},{6}
    };

    cout << "示例5结果: " << (sol.hasValidPath(grid5) ? "true" : "false") << endl;

    return 0;
}