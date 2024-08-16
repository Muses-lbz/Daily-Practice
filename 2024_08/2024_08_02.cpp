#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    // 主函数，用于求解将 nums 划分为 m 个子数组并且满足 andValues 的最小子数组值之和
    int minimumValueSum(vector<int>& nums, vector<int>& andValues) {
        int n = nums.size(), m = andValues.size();

        // 初始化记忆化数组，大小为 m * n，每个位置存储一个哈希表
        memo.resize(m * n);

        // 调用 DFS 进行搜索，初始参数为位置 0，目标数组 0，当前 AND 值为无穷大（所有位都为 1）
        int res = dfs(0, 0, INF, nums, andValues);

        // 如果结果小于 INF，则返回结果，否则返回 -1，表示无法划分
        return res < INF ? res : -1;
    }

private:
    // INF 表示一个较大的值，用于初始化当前 AND 值为所有位都为 1
    static const int INF = (1 << 20) - 1;

    // memo 用于记忆化搜索，避免重复计算
    vector<unordered_map<int, int>> memo;

    // DFS 函数，用于递归搜索最小子数组值之和
    int dfs(int i, int j, int cur, vector<int>& nums, vector<int>& andValues) {
        int n = nums.size(), m = andValues.size();
        int key = i * m + j; // 使用 i 和 j 的组合来唯一标识一个状态

        // 如果已经到达数组末尾且满足目标数组的所有条件，返回 0 表示成功
        if (i == n && j == m) return 0;

        // 如果已经遍历完 nums 或 andValues，但仍有未匹配的部分，返回 INF 表示失败
        if (i == n || j == m) return INF;

        // 如果该状态已经计算过，直接返回保存的结果
        if (memo[key].count(cur)) return memo[key][cur];

        // 更新当前 AND 值
        cur &= nums[i];

        // 如果当前 AND 值无法满足目标 AND 值，返回 INF
        if ((cur & andValues[j]) < andValues[j]) return INF;

        // 尝试继续扩展当前子数组
        int res = dfs(i + 1, j, cur, nums, andValues);

        // 如果当前 AND 值恰好满足目标 AND 值，将 nums[i] 作为当前子数组的最后一个元素并尝试下一组
        if (cur == andValues[j]) {
            res = min(res, dfs(i + 1, j + 1, INF, nums, andValues) + nums[i]);
        }

        // 保存计算结果
        memo[key][cur] = res;
        return res;
    }
};

// 主函数，用于测试和运行示例
int main() {
    Solution solution;

    // 示例输入
    vector<int> nums = { 1, 4, 3, 3, 2 };
    vector<int> andValues = { 0, 3, 3, 2 };

    // 计算并输出结果
    int result = solution.minimumValueSum(nums, andValues);
    printf("Result: %d\n", result); // 输出应为 12

    return 0;
}
