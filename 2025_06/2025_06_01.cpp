#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    // 查找最长的和谐子序列长度
    int findLHS(vector<int>& nums) {
        unordered_map<int, int> countMap; // 统计每个数字出现的次数
        int maxLen = 0;

        // 遍历数组，构建频率映射
        for (int num : nums) {
            countMap[num]++;
        }

        // 遍历哈希表，查找每个数字是否存在差值为1的数
        for (auto& [num, count] : countMap) {
            if (countMap.find(num + 1) != countMap.end()) {
                int length = count + countMap[num + 1]; // 当前和谐子序列长度
                maxLen = max(maxLen, length); // 更新最大长度
            }
        }

        return maxLen;
    }
};

int main() {
    Solution sol;

    // 示例 1
    vector<int> nums1 = { 1, 3, 2, 2, 5, 2, 3, 7 };
    cout << "示例 1 输出：" << sol.findLHS(nums1) << endl;  // 输出: 5

    // 示例 2
    vector<int> nums2 = { 1, 2, 3, 4 };
    cout << "示例 2 输出：" << sol.findLHS(nums2) << endl;  // 输出: 2

    // 示例 3
    vector<int> nums3 = { 1, 1, 1, 1 };
    cout << "示例 3 输出：" << sol.findLHS(nums3) << endl;  // 输出: 0

    return 0;
}
