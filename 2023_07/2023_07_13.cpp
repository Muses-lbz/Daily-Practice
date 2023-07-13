#include <iostream>
#include <vector>
#include <limits>

class Solution {
public:
    int minFallingPathSum(std::vector<std::vector<int>>& matrix) {
        int n = matrix.size();

        // 创建一个大小为 n x n 的二维数组 dp，并将其初始化为最大值
        std::vector<std::vector<int>> dp(n, std::vector<int>(n, std::numeric_limits<int>::max()));

        // 初始化 dp 的第一行为 matrix 的第一行
        for (int i = 0; i < n; i++) {
            dp[0][i] = matrix[0][i];
        }

        // 从第二行开始逐行计算最小下降路径和
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < n; j++) {
                // 计算当前位置的最小下降路径和，取上一行相邻位置的最小值
                int minPathSum = dp[i - 1][j];
                if (j > 0) {
                    minPathSum = std::min(minPathSum, dp[i - 1][j - 1]);
                }
                if (j < n - 1) {
                    minPathSum = std::min(minPathSum, dp[i - 1][j + 1]);
                }

                // 更新当前位置的最小下降路径和
                dp[i][j] = minPathSum + matrix[i][j];
            }
        }

        // 在最后一行中找到最小的路径和作为结果
        int minSum = std::numeric_limits<int>::max();
        for (int i = 0; i < n; i++) {
            minSum = std::min(minSum, dp[n - 1][i]);
        }

        return minSum;
    }
};

int main() {
    Solution solution;
    std::vector<std::vector<int>> matrix = {
        {3, 4, 5},
        {2, 3, 6},
        {1, 2, 4}
    };
    int result = solution.minFallingPathSum(matrix);
    std::cout << "Min Falling Path Sum: " << result << std::endl;

    return 0;
}
