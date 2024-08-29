#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool satisfiesConditions(vector<vector<int>>& grid) {
        int m = (int)grid.size();       // 获取矩阵的行数
        int n = (int)grid[0].size();    // 获取矩阵的列数

        // 遍历矩阵中的每个格子
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                // 检查下方格子是否存在，如果存在则判断当前格子是否等于下方格子
                if (i < m - 1 && grid[i][j] != grid[i + 1][j]) {
                    return false;
                }
                // 检查右方格子是否存在，如果存在则判断当前格子是否不等于右方格子
                if (j < n - 1 && grid[i][j] == grid[i][j + 1]) {
                    return false;
                }
            }
        }

        return true;  // 如果所有格子都满足条件，则返回 true
    }
};

int main() {
    // 创建一个 Solution 对象
    Solution solution;

    // 示例输入
    vector<vector<int>> grid = { {1, 0, 2}, {1, 0, 2} };

    // 调用函数并输出结果
    bool result = solution.satisfiesConditions(grid);
    cout << (result ? "true" : "false") << endl;

    return 0;
}
