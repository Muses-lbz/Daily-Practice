#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int captureForts(std::vector<int>& forts) {
        int n = forts.size(); // 城堡数组的长度
        int mx = 0; // 最多可以摧毁的敌人城堡数量
        int k = 0; // 当前连续的敌人城堡数量
        int p = 0; // 上一个城堡的状态（1为你的城堡，-1为敌人城堡）

        for (auto& x : forts) {
            if (x) { // 如果当前位置有城堡
                if (x == -p) // 如果当前城堡是敌人城堡，且与上一个城堡状态不同
                    mx = std::max(mx, k); // 更新最多可以摧毁的敌人城堡数量
                k = 0; // 重置连续的敌人城堡数量
                p = x; // 更新上一个城堡状态
            }
            else {
                k++; // 统计连续的敌人城堡数量
            }
        }

        return mx;
    }
};

int main() {
    std::vector<int> forts = { 1, 0, 0, -1, 0, 0, 0, 0, 1 };
    Solution solution;
    int result = solution.captureForts(forts);
    printf("最多可以摧毁的敌人城堡数目：%d\n", result);
    return 0;
}
