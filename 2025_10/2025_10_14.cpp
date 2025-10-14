#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    /**
     * @brief 判断从 start 开始、长度为 k 的子数组是否严格递增
     */
    bool isIncreasing(const vector<int>& nums, int start, int k) {
        for (int i = start + 1; i < start + k; ++i) {
            if (nums[i] <= nums[i - 1]) return false; // 只要有相等或下降就不行
        }
        return true;
    }

    /**
     * @brief 判断是否存在两个相邻的严格递增长度为 k 的子数组
     */
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n = (int)nums.size();

        // 至少要有两个子数组长度 k => 数组长度 >= 2k
        if (n < 2 * k) return false;

        // 遍历所有可能的起点 a
        for (int a = 0; a + 2 * k - 1 < n; ++a) {
            // 检查 nums[a..a+k-1] 和 nums[a+k..a+2k-1]
            if (isIncreasing(nums, a, k) && isIncreasing(nums, a + k, k)) {
                return true;
            }
        }
        return false;
    }
};

// 测试代码
int main() {
    Solution sol;

    vector<int> nums1 = { 2,5,7,8,9,2,3,4,3,1 };
    int k1 = 3;
    cout << "示例 1：" << endl;
    cout << "输入: [2,5,7,8,9,2,3,4,3,1], k = 3" << endl;
    cout << "输出: " << (sol.hasIncreasingSubarrays(nums1, k1) ? "true" : "false") << endl << endl;

    vector<int> nums2 = { 1,2,3,4,4,4,4,5,6,7 };
    int k2 = 5;
    cout << "示例 2：" << endl;
    cout << "输入: [1,2,3,4,4,4,4,5,6,7], k = 5" << endl;
    cout << "输出: " << (sol.hasIncreasingSubarrays(nums2, k2) ? "true" : "false") << endl;

    return 0;
}
