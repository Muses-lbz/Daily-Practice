#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>

class Solution {
public:
    long long minimumMoves(std::vector<int>& nums, int k, int maxChanges) {
        int n = (int)nums.size();

        // 辅助函数 f，计算某个位置及其相邻位置的 1 的总和
        auto f = [&](int i) -> int {
            int x = nums[i];
            if (i - 1 >= 0) {
                x += nums[i - 1];
            }
            if (i + 1 < n) {
                x += nums[i + 1];
            }
            return x;
            };

        // 初始化前缀和数组
        std::vector<long long> indexSum(n + 1), sum(n + 1);
        for (int i = 0; i < n; i++) {
            indexSum[i + 1] = indexSum[i] + nums[i] * i;
            sum[i + 1] = sum[i] + nums[i];
        }

        long long res = LLONG_MAX;
        for (int i = 0; i < n; i++) {
            // 如果当前位置及其相邻位置的 1 的总数加上 maxChanges 已经大于等于 k
            if (f(i) + maxChanges >= k) {
                if (k <= f(i)) {
                    res = std::min(res, (long long)k - nums[i]);
                }
                else {
                    res = std::min(res, (long long)2 * k - f(i) - nums[i]);
                }
                continue;
            }

            // 二分搜索找到合适的范围
            int left = 0, right = n;
            while (left <= right) {
                int mid = (left + right) / 2;
                int i1 = std::max(i - mid, 0), i2 = std::min(i + mid, n - 1);
                if (sum[i2 + 1] - sum[i1] >= k - maxChanges) {
                    right = mid - 1;
                }
                else {
                    left = mid + 1;
                }
            }

            int i1 = std::max(i - left, 0), i2 = std::min(i + left, n - 1);
            if (sum[i2 + 1] - sum[i1] > k - maxChanges) {
                i1++;
            }

            long long count1 = sum[i + 1] - sum[i1], count2 = sum[i2 + 1] - sum[i + 1];
            res = std::min(res, indexSum[i2 + 1] - indexSum[i + 1] - i * count2 + i * count1 - (indexSum[i + 1] - indexSum[i1]) + 2 * maxChanges);
        }

        return res;
    }
};

// 测试主函数
int main() {
    Solution solution;
    std::vector<int> nums = { 1, 1, 0, 0, 0, 1, 1, 0, 0, 1 };
    int k = 3;
    int maxChanges = 1;

    long long result = solution.minimumMoves(nums, k, maxChanges);
    std::cout << "最少行动次数: " << result << std::endl;

    return 0;
}
