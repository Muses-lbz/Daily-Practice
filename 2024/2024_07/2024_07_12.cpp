#include <vector>
#include <algorithm>
#include <tuple>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> fallingSquares(vector<vector<int>>& positions) {
        vector<int> ans;
        vector<tuple<int, int, int>> heights; // 存储每个放置的方块的 (left, right, height)
        int maxHeight = 0;

        for (const auto& pos : positions) {
            int left = pos[0]; // 方块的左边界
            int size = pos[1]; // 方块的边长
            int right = left + size; // 方块的右边界
            int baseHeight = 0;

            // 查找在 [left, right) 范围内的最大高度
            for (const auto& h : heights) {
                int l, r, hgt;
                tie(l, r, hgt) = h;
                if (l < right && r > left) {
                    baseHeight = max(baseHeight, hgt);
                }
            }

            int currentHeight = baseHeight + size; // 当前方块的高度
            heights.push_back(make_tuple(left, right, currentHeight)); // 将当前方块的信息存入 heights
            maxHeight = max(maxHeight, currentHeight); // 更新最大高度
            ans.push_back(maxHeight); // 将当前最大高度加入结果数组
        }

        return ans;
    }
};

int main() {
    Solution solution;

    vector<vector<int>> positions1 = { {1, 2}, {2, 3}, {6, 1} };
    vector<int> result1 = solution.fallingSquares(positions1);
    cout << "Result 1: ";
    for (int height : result1) {
        cout << height << " ";
    }
    cout << endl;

    vector<vector<int>> positions2 = { {100, 100}, {200, 100} };
    vector<int> result2 = solution.fallingSquares(positions2);
    cout << "Result 2: ";
    for (int height : result2) {
        cout << height << " ";
    }
    cout << endl;

    return 0;
}
