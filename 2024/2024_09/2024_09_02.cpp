#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    // 返回最长的“好子序列”长度
    int maximumLength(vector<int>& nums, int k) {
        int ans = 0; // 最终答案
        int len = (int)nums.size(); // 数组长度
        vector<vector<int>> dp; // 动态规划数组，dp[i][l] 表示以第 i 个元素结尾，且不同相邻元素对的数量不超过 l 的最长子序列长度
        dp.resize(len, vector<int>(51, -1)); // 初始化 dp 数组，所有值为 -1

        // 遍历所有元素，计算每个元素作为子序列结尾时的最长“好子序列”长度
        for (int i = 0; i < len; i++) {
            dp[i][0] = 1; // 长度为 1 的子序列，总是合法的“好子序列”
            for (int l = 0; l <= k; l++) {
                // 遍历 i 之前的所有元素，尝试将其加入子序列
                for (int j = 0; j < i; j++) {
                    int add = (nums[i] != nums[j]); // 如果 i 和 j 元素不同，则新增一个不同相邻元素对
                    // 如果可以通过 j 的状态更新 i 的状态，则进行更新
                    if (l - add >= 0 && dp[j][l - add] != -1) {
                        dp[i][l] = max(dp[i][l], dp[j][l - add] + 1);
                    }
                }
                // 更新当前最长的“好子序列”长度
                ans = max(ans, dp[i][l]);
            }
        }

        return ans; // 返回结果
    }
};

// 主函数
int main() {
    Solution sol; // 创建 Solution 类的实例
    vector<int> nums = { 1, 2, 1, 1, 3 }; // 输入数组
    int k = 2; // 不同相邻元素对的最大数量

    // 计算最长的“好子序列”长度并输出结果
    int result = sol.maximumLength(nums, k);
    cout << "最长好子序列的长度为: " << result << endl;

    return 0; // 程序结束
}
