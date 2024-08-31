//#include <vector>
//#include <iostream>
//
//using namespace std;
//
//class Solution {
//public:
//    bool canMakeSquare(vector<vector<char>>& grid) {
//        // 遍历矩阵的每个 2x2 子矩阵
//        for (int i = 0; i < 2; ++i) {  // 只需要检查前两行
//            for (int j = 0; j < 2; ++j) {  // 只需要检查前两列
//                // 获取当前 2x2 子矩阵的四个格子
//                char a = grid[i][j];
//                char b = grid[i][j + 1];
//                char c = grid[i + 1][j];
//                char d = grid[i + 1][j + 1];
//
//                // 检查四个格子中是否有三个或更多的颜色相同
//                int countB = (a == 'B') + (b == 'B') + (c == 'B') + (d == 'B');
//                int countW = 4 - countB;  // 白色格子的数量
//
//                // 如果有三个或四个格子颜色相同，则可以通过改变一个格子形成一个颜色完全相同的 2x2 子矩阵
//                if (countB >= 3 || countW >= 3) {
//                    return true;
//                }
//            }
//        }
//
//        // 如果没有找到符合条件的 2x2 子矩阵，返回 false
//        return false;
//    }
//};
//
//int main() {
//    Solution solution;
//    vector<vector<char>> grid = { {'B', 'W', 'B'}, {'B', 'W', 'W'}, {'B', 'W', 'B'} };
//
//    bool result = solution.canMakeSquare(grid);
//    cout << (result ? "true" : "false") << endl;
//
//    return 0;
//}

#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    bool canMakeSquare(vector<vector<char>>& grid) {
        // 遍历 5x5 矩阵中的每个 2x2 子矩阵
        for (int i = 0; i < 4; ++i) {  // 遍历行 (0 到 3)
            for (int j = 0; j < 4; ++j) {  // 遍历列 (0 到 3)
                // 获取当前 2x2 子矩阵的四个格子
                char a = grid[i][j];
                char b = grid[i][j + 1];
                char c = grid[i + 1][j];
                char d = grid[i + 1][j + 1];

                // 检查四个格子中是否有三个或更多的颜色相同
                int countB = (a == 'B') + (b == 'B') + (c == 'B') + (d == 'B');
                int countW = 4 - countB;  // 白色格子的数量

                // 如果有三个或四个格子颜色相同，则可以通过改变一个格子形成一个颜色完全相同的 2x2 子矩阵
                if (countB >= 3 || countW >= 3) {
                    return true;
                }
            }
        }

        // 如果没有找到符合条件的 2x2 子矩阵，返回 false
        return false;
    }
};

int main() {
    Solution solution;
    vector<vector<char>> grid = {
        {'B', 'W', 'B', 'W', 'B'},
        {'W', 'B', 'W', 'B', 'W'},
        {'B', 'W', 'B', 'W', 'B'},
        {'W', 'B', 'W', 'B', 'W'},
        {'B', 'W', 'B', 'W', 'B'}
    };

    bool result = solution.canMakeSquare(grid);
    cout << (result ? "true" : "false") << endl;

    return 0;
}
