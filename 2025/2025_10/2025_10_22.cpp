#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <algorithm>

using namespace std;

/**
 * 题目：执行操作后元素的最高频率 II
 *
 * 思路：
 * 你可以对 numOperations 个不同下标的元素执行操作，
 * 每次操作可将 nums[i] 增减到 [nums[i]-k, nums[i]+k] 的任意整数。
 *
 * 我们要找一个目标值 mode，使得：
 *   尽可能多的元素（经最多 numOperations 次调整后）可以变成 mode。
 *
 * 解法思路：
 * 1️⃣ 排序 nums，方便用二分查找。
 * 2️⃣ 统计每个数出现次数（哈希表 numCount）。
 * 3️⃣ 对于每个数 value，我们把它的 value, value±k 都加入候选集合 modes。
 * 4️⃣ 对每个候选 mode：
 *     - 用二分找到 nums 中在 [mode - k, mode + k] 范围内的元素数目；
 *     - 如果 mode 已存在 numCount[mode] 个，则还能用 numOperations 次操作补上；
 *       否则最多补 numOperations 次；
 *     - 所以最大频率 = min(区间元素数, numCount[mode] + numOperations)。
 * 5️⃣ 最终取所有 mode 的最大值。
 */

class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        // 排序数组，方便区间二分查找
        sort(nums.begin(), nums.end());
        int ans = 0;

        unordered_map<int, int> numCount; // 每个数的出现次数
        set<int> modes;                   // 候选目标值（mode）

        // 工具函数：把 value 及其 ±k 加入候选集合
        auto addMode = [&](int value) {
            modes.insert(value);
            if (value - k >= nums.front()) modes.insert(value - k);
            if (value + k <= nums.back()) modes.insert(value + k);
            };

        // 统计每个数的出现次数，并加入候选 mode
        int lastNumIndex = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != nums[lastNumIndex]) {
                numCount[nums[lastNumIndex]] = i - lastNumIndex;
                ans = max(ans, i - lastNumIndex);
                addMode(nums[lastNumIndex]);
                lastNumIndex = i;
            }
        }
        // 处理最后一段
        numCount[nums[lastNumIndex]] = (int)nums.size() - lastNumIndex;
        ans = max(ans, (int)nums.size() - lastNumIndex);
        addMode(nums[lastNumIndex]);

        // 二分查找左边界：第一个 >= value 的下标
        auto leftBound = [&](int value) {
            int left = 0, right = (int)nums.size() - 1;
            while (left < right) {
                int mid = (left + right) / 2;
                if (nums[mid] < value) left = mid + 1;
                else right = mid;
            }
            return left;
            };

        // 二分查找右边界：最后一个 <= value 的下标
        auto rightBound = [&](int value) {
            int left = 0, right = (int)nums.size() - 1;
            while (left < right) {
                int mid = (left + right + 1) / 2;
                if (nums[mid] > value) right = mid - 1;
                else left = mid;
            }
            return left;
            };

        // 遍历所有候选 mode，计算最大频率
        for (int mode : modes) {
            int l = leftBound(mode - k);
            int r = rightBound(mode + k);

            // 区间 [mode - k, mode + k] 中的元素个数
            int rangeCount = r - l + 1;

            int tempAns;
            if (numCount.count(mode)) {
                // mode 原本已有 numCount[mode] 个元素
                tempAns = min(rangeCount, numCount[mode] + numOperations);
            }
            else {
                // mode 原本不存在，只能靠操作变成它
                tempAns = min(rangeCount, numOperations);
            }
            ans = max(ans, tempAns);
        }

        return ans;
    }
};

// ========================= 测试主函数 =========================
int main() {
    Solution sol;

    vector<int> nums1 = { 1, 4, 5 };
    int k1 = 1, ops1 = 2;
    cout << "示例 1:" << endl;
    cout << "输入: [1,4,5], k=1, numOperations=2" << endl;
    cout << "输出: " << sol.maxFrequency(nums1, k1, ops1) << " (期望: 2)" << endl;
    cout << endl;

    vector<int> nums2 = { 5, 11, 20, 20 };
    int k2 = 5, ops2 = 1;
    cout << "示例 2:" << endl;
    cout << "输入: [5,11,20,20], k=5, numOperations=1" << endl;
    cout << "输出: " << sol.maxFrequency(nums2, k2, ops2) << " (期望: 2)" << endl;
    cout << endl;

    vector<int> nums3 = { 1, 2, 4, 7, 10 };
    int k3 = 2, ops3 = 2;
    cout << "示例 3:" << endl;
    cout << "输入: [1,2,4,7,10], k=2, numOperations=2" << endl;
    cout << "输出: " << sol.maxFrequency(nums3, k3, ops3) << endl;

    return 0;
}
