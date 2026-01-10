#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // 计算所有整数对的数位差之和
    long long sumDigitDifferences(vector<int>& nums) {
        long long res = 0; // 存储最终结果
        int n = (int)nums.size(); // 数组的大小

        // 当数字还没有处理完所有数位时，继续循环
        while (nums[0] > 0) {
            vector<int> cnt(10); // 统计当前数位上0-9各个数字出现的次数

            // 遍历每个数字，提取当前最低位的数字并统计
            for (int i = 0; i < n; i++) {
                cnt[nums[i] % 10]++; // 提取当前数的最低位数字并统计
                nums[i] /= 10; // 去掉当前最低位的数字，为处理下一位做准备
            }

            // 计算当前数位的数位差贡献
            for (int i = 0; i < 10; i++) {
                res += (long long)(n - cnt[i]) * cnt[i]; // 贡献计入结果
            }
        }

        // 返回结果，需要除以2，因为每对数位差计算了两次（对称）
        return res / 2;
    }
};

int main() {
    Solution solution; // 创建 Solution 类的实例
    vector<int> nums = { 13, 23, 12 }; // 输入数组
    long long result = solution.sumDigitDifferences(nums); // 计算数位差之和
    cout << "数位差之和为: " << result << endl; // 输出结果

    return 0;
}
