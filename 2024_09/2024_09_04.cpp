#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        int len = (int)nums.size();
        unordered_map<int, vector<int>> dp;  // dp数组，用来保存每个数对应的最长"好"子序列长度
        vector<int> zd(k + 1, 0);  // 保存全局的"好"子序列长度，最多k个不同的相邻元素

        // 遍历每个数
        for (int i = 0; i < len; i++) {
            int v = nums[i];
            // 如果dp中还没有当前数v的记录，则为它创建一个k+1长度的数组
            if (!dp.count(v)) {
                dp[v] = vector<int>(k + 1, 0);
            }

            auto& tmp = dp[v];  // 取出当前数v的dp数组
            // 更新当前数v在不同允许次数下的最长子序列长度
            for (int j = 0; j <= k; j++) {
                ++tmp[j];  // 当前数自身算作一个子序列
                if (j > 0) {
                    // 如果允许j个不同的相邻元素，尝试通过前一个状态+1来更新
                    tmp[j] = max(tmp[j], zd[j - 1] + 1);
                }
            }

            // 更新全局的zd数组
            for (int j = 0; j <= k; j++) {
                zd[j] = max(zd[j], tmp[j]);
            }
        }
        return zd[k];  // 返回允许k个不同相邻元素时的最长"好"子序列长度
    }
};

// 补全主函数
int main() {
    Solution solution;
    vector<int> nums = { 1, 2, 1, 1, 3 };
    int k = 2;

    // 输出最长"好"子序列的长度
    cout << "最长好子序列的长度: " << solution.maximumLength(nums, k) << endl;

    return 0;
}
