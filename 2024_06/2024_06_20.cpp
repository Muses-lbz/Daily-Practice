#include <iostream>
#include <vector>

class Solution {
public:
    const int MOD = 1000000007; // 模数 10^9 + 7，直接使用整型常量

    int specialPerm(std::vector<int>& nums) {
        int n = (int)nums.size();
        // 使用 dp 数组来记忆已经计算过的状态
        // dp[mask][i] 表示以 nums[i] 结尾，且使用了 mask 表示的子集的特别排列数
        std::vector<std::vector<int>> dp(1LL << n, std::vector<int>(n, 0));

        // 初始化每个单个元素的状态
        for (int i = 0; i < n; ++i) {
            dp[1LL << i][i] = 1;
        }

        // 遍历所有的状态
        for (long long mask = 0; mask < (1LL << n); ++mask) {
            for (int i = 0; i < n; ++i) {
                // 如果当前 mask 不包含 nums[i]，则跳过
                if (!(mask & (1LL << i))) continue;

                // 尝试添加新的元素到当前排列中
                for (int j = 0; j < n; ++j) {
                    // 如果 nums[j] 已经在 mask 中，则跳过
                    if (mask & (1LL << j)) continue;

                    // 检查 nums[i] 和 nums[j] 是否满足条件
                    if (nums[i] % nums[j] == 0 || nums[j] % nums[i] == 0) {
                        dp[mask | (1LL << j)][j] = (dp[mask | (1LL << j)][j] + dp[mask][i]) % MOD;
                    }
                }
            }
        }

        // 计算所有以任意元素结尾的全排列的特别排列数
        int result = 0;
        for (int i = 0; i < n; ++i) {
            result = (result + dp[(1LL << n) - 1][i]) % MOD;
        }

        return result;
    }
};

int main() {
    Solution solution;
    std::vector<int> nums = { 2, 3, 6 }; // 示例输入
    int result = solution.specialPerm(nums); // 计算特别排列的总数目
    std::cout << "特别排列的总数目: " << result << std::endl; // 输出结果
    return 0;
}
