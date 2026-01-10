#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];

        // 创建一个数组来存储最高金额
        vector<int> dp(n, 0);

        // 初始化前两个元素
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);

        // 从第三个房屋开始计算最高金额
        for (int i = 2; i < n; ++i) {
            // 在偷窃当前房屋和不偷窃当前房屋之间选择最大值
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
        }

        // 返回最后一个元素即为答案
        return dp[n - 1];
    }
};

int main() {
    vector<int> nums = { 1, 2, 3, 1 };
    Solution solution;
    int result = solution.rob(nums);
    cout << "能够偷窃到的最高金额是：" << result << endl;
    return 0;
}
