#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
        // 创建一个大小为 8x8 的棋盘，初始化为 0
        vector<vector<int>> chessboard(8, vector<int>(8, 0));

        // 标记黑皇后的位置
        for (const auto& queen : queens) {
            chessboard[queen[0]][queen[1]] = 1;
        }

        vector<vector<int>> result;
        // 八个可能的方向
        int directions[8][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1} };

        for (const auto& dir : directions) {
            int x = king[0] + dir[0];
            int y = king[1] + dir[1];

            while (x >= 0 && x < 8 && y >= 0 && y < 8) {
                if (chessboard[x][y] == 1) {
                    result.push_back({ x, y });
                    break;
                }
                x += dir[0];
                y += dir[1];
            }
        }

        return result;
    }
};

int main() {
    Solution solution;

    vector<vector<int>> queens = { {0,1},{1,0},{4,0},{0,4},{3,3},{2,4} };
    vector<int> king = { 0, 0 };

    vector<vector<int>> result = solution.queensAttacktheKing(queens, king);

    // 输出结果
    cout << "可以攻击国王的皇后坐标：" << endl;
    for (const auto& coord : result) {
        cout << "(" << coord[0] << "," << coord[1] << ")" << endl;
    }

    return 0;
}
