#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    long long countAlternatingSubarrays(vector<int>& nums) {
        long long count = 0;
        int n = (int)nums.size();
        long long start = 0;

        while (start < n) {
            long long end = start;

            // 确定最大交替子数组的结束位置
            while (end + 1 < n && nums[end] != nums[end + 1]) {
                end++;
            }

            // 计算从start到end的所有交替子数组的数量
            long long length = end - start + 1;
            count += (length * (length + 1)) / 2;

            // 移动起始位置到新的起点
            start = end + 1;
        }

        return count;
    }
};

int main() {
    // 创建Solution对象
    Solution solution;

    // 示例输入
    vector<int> nums = { 0, 1, 1, 1, 1 };

    // 调用countAlternatingSubarrays函数并输出结果
    long long result = solution.countAlternatingSubarrays(nums);
    cout << "交替子数组的数量: " << result << endl;

    return 0;
}
