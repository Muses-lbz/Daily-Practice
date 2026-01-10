#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int n = (int)grid.size();
        vector<int> rowMax(n, 0); // 每行的最大值
        vector<int> colMax(n, 0); // 每列的最大值

        // 计算每行和每列的最大值
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                rowMax[i] = max(rowMax[i], grid[i][j]);
                colMax[j] = max(colMax[j], grid[i][j]);
            }
        }

        int totalIncrease = 0;

        // 计算最大高度增量总和
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                // 当前建筑物能增加的最大高度
                int maxHeight = min(rowMax[i], colMax[j]);
                totalIncrease += maxHeight - grid[i][j];
            }
        }

        return totalIncrease;
    }
};

// 主函数用于测试
int main() {
    Solution sol;

    vector<vector<int>> grid1 = { {3,0,8,4},{2,4,5,7},{9,2,6,3},{0,3,1,0} };
    int result1 = sol.maxIncreaseKeepingSkyline(grid1);
    printf("示例1的结果: %d\n", result1); // 输出: 35

    return 0;
}
