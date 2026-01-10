#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxConsecutive(int bottom, int top, vector<int>& special) {
        // 排序特殊楼层
        sort(special.begin(), special.end());

        // 初始化最大连续楼层数
        int maxConsec = 0;

        // 处理从 bottom 到第一个特殊楼层之间的连续楼层
        maxConsec = special.empty() ? top - bottom + 1 : special[0] - bottom;

        // 处理特殊楼层之间的连续楼层
        for (int i = 1; i < special.size(); i++) {
            maxConsec = max(maxConsec, special[i] - special[i - 1] - 1);
        }

        // 处理从最后一个特殊楼层到 top 之间的连续楼层
        maxConsec = max(maxConsec, top - special.back());

        return maxConsec;
    }
};

int main() {
    Solution solution;
    vector<int> special1 = { 4, 6 };
    cout << solution.maxConsecutive(2, 9, special1) << endl;  // 输出 3

    vector<int> special2 = { 7, 6, 8 };
    cout << solution.maxConsecutive(6, 8, special2) << endl;  // 输出 0

    return 0;
}
