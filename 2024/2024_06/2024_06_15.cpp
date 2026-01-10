#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        // 将数组进行排序
        sort(nums.begin(), nums.end());
        int n = (int)nums.size();
        int maxBeauty = 1; // 初始化最大美丽值为1（至少一个元素）
        int left = 0; // 滑动窗口的左边界

        // 使用滑动窗口来寻找满足条件的最长子序列
        for (int right = 0; right < n; ++right) {
            // 当窗口中的最大值和最小值的差超过2*k时，移动左边界
            while (nums[right] - nums[left] > 2 * k) {
                ++left;
            }
            // 更新最大美丽值
            maxBeauty = max(maxBeauty, right - left + 1);
        }

        return maxBeauty;
    }
};

// 主函数，用于测试
int main() {
    Solution solution;
    vector<int> nums = { 4, 6, 1, 2 }; // 示例输入
    int k = 2; // 示例中的k值
    int result = solution.maximumBeauty(nums, k); // 调用函数计算最大美丽值
    cout << "最大美丽值是: " << result << endl; // 输出结果
    return 0;
}
