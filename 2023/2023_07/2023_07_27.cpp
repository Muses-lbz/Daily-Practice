//#include <iostream>
//#include <vector>
//#include <math.h>
//#include <algorithm>
//
//class Solution {
//public:
//    int deleteGreatestValue(std::vector<std::vector<int>>& grid) {
//        int m = grid.size(), n = grid[0].size(), s = 0;
//        for (auto& v : grid)
//            sort(v.begin(), v.end());
//        for (int j = 0; j < n; j++) {
//            int mx = INT_MIN;
//            for (int i = 0; i < m; i++)
//                mx = std::max(mx, grid[i][j]);
//            s += mx;
//        }
//        return s;
//    }
//};
//
//int main() {
//    Solution solution;
//    std::vector<std::vector<int>> grid = { {1, 2, 4}, {3, 3, 1} };
//    int answer = solution.deleteGreatestValue(grid);
//    std::cout << "Answer: " << answer << std::endl;
//
//    return 0;
//}

#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>

class Solution {
public:
    int deleteGreatestValue(std::vector<std::vector<int>>& grid) {
        int m = grid.size();        // 矩阵的行数
        int n = grid[0].size();     // 矩阵的列数
        int s = 0;                  // 变量用于存储所有最大值的和

        // 对每一行进行升序排序
        for (auto& v : grid)
            std::sort(v.begin(), v.end());

        // 遍历每一列
        for (int j = 0; j < n; j++) {
            int mx = INT_MIN;       // 变量用于存储当前列中的最大值

            // 找到当前列中的最大值
            for (int i = 0; i < m; i++)
                mx = std::max(mx, grid[i][j]);

            s += mx;                // 将最大值加到和中
        }

        return s;                   // 返回最终的和作为结果
    }
};

int main() {
    Solution solution;
    std::vector<std::vector<int>> grid = { {1, 2, 4}, {3, 3, 1} };
    int answer = solution.deleteGreatestValue(grid);
    std::cout << "Answer: " << answer << std::endl;

    return 0;
}
