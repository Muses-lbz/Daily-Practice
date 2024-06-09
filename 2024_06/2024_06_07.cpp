#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <cstring>

using namespace std;

class Solution {
public:
    int maxOperations(vector<int>& nums) {
        int n = (int)nums.size();
        // 使用二维vector替代变长数组
        vector<vector<int>> memo(n, vector<int>(n, -1));

        // 辅助函数，计算在区间 [i, j] 内，最大可以进行多少次操作
        auto helper = [&](int i, int j, int target) -> int {
            // 定义递归函数 dfs
            function<int(int, int)> dfs = [&](int i, int j) -> int {
                if (i >= j) {
                    return 0; // 如果区间无效，返回 0
                }
                if (memo[i][j] != -1) {
                    return memo[i][j]; // 如果已经计算过，直接返回记忆化结果
                }
                int ans = 0;
                // 检查从左侧开始的两个元素
                if (i + 1 < n && nums[i] + nums[i + 1] == target) {
                    ans = max(ans, 1 + dfs(i + 2, j));
                }
                // 检查从右侧开始的两个元素
                if (j - 1 >= 0 && nums[j - 1] + nums[j] == target) {
                    ans = max(ans, 1 + dfs(i, j - 2));
                }
                // 检查从两端各取一个元素
                if (nums[i] + nums[j] == target) {
                    ans = max(ans, 1 + dfs(i + 1, j - 1));
                }
                memo[i][j] = ans; // 记忆化结果
                return ans;
                };

            return dfs(i, j);
            };

        // 主函数逻辑，计算三种不同目标和的最大操作次数
        int res = 0;
        res = max(res, helper(0, n - 1, nums[0] + nums[n - 1]));
        res = max(res, helper(0, n - 1, nums[0] + nums[1]));
        res = max(res, helper(0, n - 1, nums[n - 2] + nums[n - 1]));
        return res;
    }
};

// 主函数，测试用例
int main() {
    Solution solution;
    vector<int> nums = { 3, 2, 1, 6, 5, 4 };
    int result = solution.maxOperations(nums);
    cout << "最大操作次数: " << result << endl; // 输出最大操作次数
    return 0;
}
