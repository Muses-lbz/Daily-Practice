#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minimumDeleteSum(const string& s1, const string& s2) {
        // 使用 size_t，与 size() 返回类型一致
        size_t n = s1.size();
        size_t m = s2.size();

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        // 边界初始化
        for (size_t i = 1; i <= n; ++i) {
            dp[i][0] = dp[i - 1][0] + static_cast<unsigned char>(s1[i - 1]);
        }

        for (size_t j = 1; j <= m; ++j) {
            dp[0][j] = dp[0][j - 1] + static_cast<unsigned char>(s2[j - 1]);
        }

        // 状态转移
        for (size_t i = 1; i <= n; ++i) {
            for (size_t j = 1; j <= m; ++j) {
                if (s1[i - 1] == s2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else {
                    dp[i][j] = min(
                        dp[i - 1][j] + static_cast<unsigned char>(s1[i - 1]),
                        dp[i][j - 1] + static_cast<unsigned char>(s2[j - 1])
                    );
                }
            }
        }

        return dp[n][m];
    }
};

int main()
{
    Solution solution;

    cout << solution.minimumDeleteSum("sea", "eat") << endl;
    cout << solution.minimumDeleteSum("delete", "leet") << endl;

    return 0;
}
