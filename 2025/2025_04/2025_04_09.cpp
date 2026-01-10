#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    // 函数功能：将数组 nums 中所有元素通过合法操作变为目标值 k，返回最少操作次数
    int minOperations(vector<int>& nums, int k) {
        // 遍历数组，如果存在小于 k 的值，说明无法通过操作变为 k，直接返回 -1
        for (int x : nums) {
            if (x < k) return -1;
        }

        // 使用集合记录所有大于 k 的不同数值
        // 因为每种不同的数值都需要一次操作将其压缩为某个更小的合法值
        set<int> s;
        for (int x : nums) {
            if (x > k) {
                s.insert(x);
            }
        }

        // 集合中元素的个数就是所需的最少操作次数
        // 因为每次只能压缩一个合法层级
        return (int)s.size();
    }
};

int main() {
    Solution solution;

    // 示例 1
    vector<int> nums1 = { 5, 2, 5, 4, 5 };
    int k1 = 2;
    int result1 = solution.minOperations(nums1, k1);
    cout << "示例 1 输出: " << result1 << endl; // 期望输出 2

    // 示例 2
    vector<int> nums2 = { 2, 1, 2 };
    int k2 = 2;
    int result2 = solution.minOperations(nums2, k2);
    cout << "示例 2 输出: " << result2 << endl; // 期望输出 -1

    // 示例 3：已经全是 k
    vector<int> nums3 = { 3, 3, 3 };
    int k3 = 3;
    int result3 = solution.minOperations(nums3, k3);
    cout << "示例 3 输出: " << result3 << endl; // 期望输出 0

    return 0;
}
