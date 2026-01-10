#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];

        // 偷窃第一个房屋到倒数第二个房屋之间的最大金额
        vector<int> dp1(n);
        dp1[0] = nums[0];
        dp1[1] = max(nums[0], nums[1]);
        for (int i = 2; i < n - 1; ++i) {
            dp1[i] = max(dp1[i - 2] + nums[i], dp1[i - 1]);
        }

        // 不偷窃第一个房屋到最后一个房屋之间的最大金额
        vector<int> dp2(n);
        dp2[0] = 0;
        dp2[1] = nums[1];
        for (int i = 2; i < n; ++i) {
            dp2[i] = max(dp2[i - 2] + nums[i], dp2[i - 1]);
        }

        // 返回两个子问题的最大值
        return max(dp1[n - 2], dp2[n - 1]);
    }
};

int main() {
    Solution solution;
    vector<int> nums = { 2, 3, 2 };
    int result = solution.rob(nums);
    cout << "今晚能够偷窃到的最高金额是：" << result << endl;
    return 0;
}
