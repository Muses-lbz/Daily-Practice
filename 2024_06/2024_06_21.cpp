#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int temperatureTrend(vector<int>& temperatureA, vector<int>& temperatureB) {
        // 辅助函数，计算两天之间的气温趋势
        auto getTrend = [](int x, int y) -> int {
            if (x == y) {
                return 0; // 平稳趋势
            }
            return x < y ? -1 : 1; // 上升趋势或下降趋势
            };

        int n = (int)temperatureA.size(); // 气温数组的大小
        int ans = 0, cur = 0; // 初始化结果和当前连续相同趋势天数

        // 遍历所有的天数，计算每两天之间的趋势
        for (int i = 1; i < n; ++i) {
            int ta = getTrend(temperatureA[i - 1], temperatureA[i]); // 地区A的趋势
            int tb = getTrend(temperatureB[i - 1], temperatureB[i]); // 地区B的趋势

            if (ta == tb) {
                ++cur; // 如果趋势相同，当前连续相同趋势天数加1
                ans = max(ans, cur); // 更新最大连续相同趋势天数
            }
            else {
                cur = 0; // 如果趋势不同，重置当前连续相同趋势天数
            }
        }
        return ans; // 返回最大连续相同趋势天数
    }
};

int main() {
    Solution solution;

    // 示例1
    vector<int> temperatureA1 = { 21, 18, 18, 18, 31 };
    vector<int> temperatureB1 = { 34, 32, 16, 16, 17 };
    cout << "最大连续相同趋势天数（示例1）：" << solution.temperatureTrend(temperatureA1, temperatureB1) << endl;

    // 你可以在这里添加更多的测试用例
    vector<int> temperatureA2 = { 21, 21, 23, 24, 25 };
    vector<int> temperatureB2 = { 20, 20, 22, 23, 24 };
    cout << "最大连续相同趋势天数（示例2）：" << solution.temperatureTrend(temperatureA2, temperatureB2) << endl;

    return 0;
}
