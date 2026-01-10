#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
using namespace std;

class Solution {
public:
    int minSkips(vector<int>& dist, int speed, int hoursBefore) {
        int n = dist.size();
        // 创建动态规划表，dp[i][j] 表示通过前 i 条道路时，跳过 j 次休息时间所需的最小时间
        vector<vector<long long>> dp(n + 1, vector<long long>(n + 1, numeric_limits<long long>::max()));

        // 初始条件：在没有经过任何道路时，不需要跳过任何休息时间，所需时间为0
        dp[0][0] = 0;

        // 动态规划填表
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j <= i; ++j) {
                // 选择跳过休息时间的情况
                if (j > 0 && dp[i - 1][j - 1] != numeric_limits<long long>::max()) {
                    // 跳过休息时间后，所需时间
                    long long skip_time = dp[i - 1][j - 1] + dist[i - 1];
                    // 检查是否会发生整数溢出
                    if (skip_time <= numeric_limits<long long>::max() - speed) {
                        dp[i][j] = min(dp[i][j], skip_time);
                    }
                }
                // 不跳过休息时间的情况
                if (dp[i - 1][j] != numeric_limits<long long>::max()) {
                    // 不跳过休息时间后，所需时间
                    long long no_skip_time = (dp[i - 1][j] + dist[i - 1] + speed - 1) / speed * speed;
                    // 检查是否会发生整数溢出
                    if (no_skip_time <= numeric_limits<long long>::max() - dist[i - 1]) {
                        dp[i][j] = min(dp[i][j], no_skip_time);
                    }
                }
            }
        }

        // 找到最小跳过次数
        for (int j = 0; j <= n; ++j) {
            if (dp[n][j] <= (long long)hoursBefore * speed) {
                return j;
            }
        }

        // 无法准时参会
        return -1;
    }
};

int main() {
    // 示例输入
    vector<int> dist = { 1, 3, 2 };
    int speed = 4;
    int hoursBefore = 2;

    Solution sol;
    // 调用函数计算最小跳过次数
    int min_skips = sol.minSkips(dist, speed, hoursBefore);
    // 输出结果
    cout << "最小跳过次数：" << min_skips << endl;

    return 0;
}
