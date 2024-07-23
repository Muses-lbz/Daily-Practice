#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
    vector<vector<int>> modifiedMatrix(vector<vector<int>>& matrix) {
        int m = (int)matrix.size();
        int n = (int)matrix[0].size();

        // 初始化 answer 矩阵为与 matrix 相同
        vector<vector<int>> answer = matrix;

        // 创建一个数组记录每一列的最大值
        vector<int> maxInColumn(n, INT_MIN);

        // 遍历矩阵，找到每一列的最大值
        for (int j = 0; j < n; ++j) {
            for (int i = 0; i < m; ++i) {
                if (matrix[i][j] > maxInColumn[j]) {
                    maxInColumn[j] = matrix[i][j];
                }
            }
        }

        // 再次遍历矩阵，将 answer 中每个值为 -1 的元素替换为所在列的最大值
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == -1) {
                    answer[i][j] = maxInColumn[j];
                }
            }
        }

        return answer;
    }
};

int main() {
    Solution solution;

    // 示例输入矩阵
    vector<vector<int>> matrix = {
        {1, -1, 3},
        {4, 5, -1},
        {-1, 8, 9}
    };

    // 调用 modifiedMatrix 方法
    vector<vector<int>> answer = solution.modifiedMatrix(matrix);

    // 打印输出矩阵
    for (const auto& row : answer) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}
